/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/memcpy-decomp
 * memcpy-decomp.hpp
 */
#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>
#include <utility>

#if defined(_MSC_VER) && !defined(__clang__)
	#define MEMCPY_DECOMP_INLINE [[msvc::forceinline]] inline
#else
	#define MEMCPY_DECOMP_INLINE inline __attribute__((always_inline))
#endif

namespace memcpy_decomp {

#if defined(__AVX512F__)
	inline constexpr uint64_t register_width{ 64 };
#elif defined(__AVX__)
	inline constexpr uint64_t register_width{ 32 };
#else
	inline constexpr uint64_t register_width{ 16 };
#endif

	template<uint64_t size> MEMCPY_DECOMP_INLINE void pow2_memcpy(std::byte* __restrict dst, const std::byte* __restrict src) noexcept {
		static_assert(std::has_single_bit(size), "Sorry, but you can only memcpy a power-of-2 size.");
		std::memcpy(dst, src, size);
	}

	template<uint64_t bucket_size, typename sequence_type> struct memcpy_runner_impl;

	template<uint64_t bucket_size, uint64_t... indices> struct memcpy_runner_impl<bucket_size, std::integer_sequence<uint64_t, indices...>> {
		static_assert(std::has_single_bit(bucket_size), "Sorry, but buckets must be a power-of-2 size.");
		static constexpr uint64_t chunk_size{ bucket_size < register_width ? bucket_size : register_width };
		static constexpr uint64_t chunk_count{ bucket_size / chunk_size };
		MEMCPY_DECOMP_INLINE static void impl(std::byte* __restrict dst, const std::byte* __restrict src, uint64_t byte_count) noexcept {
			std::byte* __restrict dst_tail		 = dst + byte_count - bucket_size;
			const std::byte* __restrict src_tail = src + byte_count - bucket_size;
			(pow2_memcpy<chunk_size>(dst + indices * chunk_size, src + indices * chunk_size), ...);
			(pow2_memcpy<chunk_size>(dst_tail + indices * chunk_size, src_tail + indices * chunk_size), ...);
		}
	};

	template<uint64_t bucket_size> struct memcpy_runner {
		static_assert(std::has_single_bit(bucket_size), "Sorry, but buckets must be a power-of-2 size.");
		static constexpr uint64_t chunk_size{ bucket_size < register_width ? bucket_size : register_width };
		static constexpr uint64_t chunk_count{ bucket_size / chunk_size };

		MEMCPY_DECOMP_INLINE static void impl(std::byte* __restrict dst, const std::byte* __restrict src, uint64_t byte_count) noexcept {
			memcpy_runner_impl<bucket_size, std::make_integer_sequence<uint64_t, chunk_count>>::impl(dst, src, byte_count);
		}
	};

	inline constexpr uint64_t fallback_bucket_index{ 9 };

	template<uint64_t max_bytes> inline constexpr uint64_t max_bytes_bucket_index{ static_cast<uint64_t>(std::bit_width(max_bytes)) };

	template<uint64_t max_bytes>
	inline constexpr uint64_t top_bucket_index{ max_bytes_bucket_index<max_bytes> < fallback_bucket_index ? max_bytes_bucket_index<max_bytes> : fallback_bucket_index };

	template<uint64_t bucket_index> MEMCPY_DECOMP_INLINE void copy_bucket(std::byte* __restrict dst, const std::byte* __restrict src, uint64_t byte_count) noexcept {
		if constexpr (bucket_index == 1) {
			*dst = *src;
		} else if constexpr (bucket_index == fallback_bucket_index) {
			std::memcpy(dst, src, byte_count);
		} else if constexpr (bucket_index > 1) {
			memcpy_runner<1ull << (bucket_index - 1)>::impl(dst, src, byte_count);
		}
	}

	template<uint64_t low_index, uint64_t high_index>
	MEMCPY_DECOMP_INLINE void dispatch_buckets(std::byte* __restrict dst, const std::byte* __restrict src, uint64_t byte_count) noexcept {
		if constexpr (low_index == high_index) {
			copy_bucket<low_index>(dst, src, byte_count);
		} else {
			constexpr uint64_t split_index{ (low_index + high_index + 1) / 2 };
			if (byte_count < (1ull << (split_index - 1))) {
				dispatch_buckets<low_index, split_index - 1>(dst, src, byte_count);
			} else {
				dispatch_buckets<split_index, high_index>(dst, src, byte_count);
			}
		}
	}

	template<uint64_t max_bytes>
	MEMCPY_DECOMP_INLINE void memcpy_decomp_up_to(void* __restrict dst_new, const void* __restrict src_new, uint64_t byte_count) noexcept {
		std::byte* __restrict dst		= static_cast<std::byte*>(dst_new);
		const std::byte* __restrict src = static_cast<const std::byte*>(src_new);
		dispatch_buckets<0, top_bucket_index<max_bytes>>(dst, src, byte_count);
	}

	MEMCPY_DECOMP_INLINE void memcpy_decomp(void* __restrict dst, const void* __restrict src, uint64_t byte_count) noexcept {
		memcpy_decomp_up_to<std::numeric_limits<uint64_t>::max()>(dst, src, byte_count);
	}

}
