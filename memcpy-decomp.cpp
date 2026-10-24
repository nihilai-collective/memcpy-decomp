/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Nihilai Collective Corp
 * https://github.com/nihilai-collective/memcpy-decomp
 * memcpy-decomp.cpp
 */

#include "memcpy-decomp.hpp"
#include <benchmarksuite>
#include <rt-ut>
#include <array>
#include <utility>

namespace memcpy_decomp_bench {

#if defined(NDEBUG)
	inline constexpr uint64_t iteration_element_budget{ 400ull * 100000ull };
	inline constexpr uint64_t measured_iteration_count{ 60 };
#else
	inline constexpr uint64_t iteration_element_budget{ 40ull * 100000ull };
	inline constexpr uint64_t measured_iteration_count{ 10 };
#endif

	template<uint64_t count = 100000ull>
		requires(count > 0)
	consteval uint64_t max_iterations_for() noexcept {
		constexpr uint64_t computed{ iteration_element_budget / count };
		return computed < measured_iteration_count ? measured_iteration_count : computed;
	}

	inline constexpr double convergence_threshold{ 5.0 };
	inline constexpr double rse_threshold{ 10.0 };

	inline constexpr benchmarksuite::stage_config_data config{ .clear_cpu_caches_before_iterations = true,
		.include_non_converged_results															   = true,
		.measured_iteration_count																   = measured_iteration_count,
		.max_iteration_count																	   = max_iterations_for<100000ull>(),
		.convergence_threshold																	   = convergence_threshold,
		.max_time_in_s																			   = 10,
		.rse_threshold																			   = rse_threshold };

	template<uint64_t count> consteval benchmarksuite::stage_config_data config_for() noexcept {
		return benchmarksuite::stage_config_data{ .clear_cpu_caches_before_iterations = config.clear_cpu_caches_before_iterations,
			.include_non_converged_results											  = config.include_non_converged_results,
			.measured_iteration_count												  = config.measured_iteration_count,
			.max_iteration_count													  = max_iterations_for<count>(),
			.convergence_threshold													  = config.convergence_threshold,
			.benchmark_type															  = config.benchmark_type,
			.max_time_in_s															  = config.max_time_in_s,
			.rse_threshold															  = config.rse_threshold,
			.max_k																	  = config.max_k,
			.min_k																	  = config.min_k };
	}

	struct std_memcpy_copier {
		BNCH_SWT_HOST static void impl(std::byte* __restrict dst, const std::byte* __restrict src, uint64_t length) noexcept {
			std::memcpy(dst, src, length);
		}
	};

	struct memcpy_decomp_copier {
		BNCH_SWT_HOST static void impl(std::byte* __restrict dst, const std::byte* __restrict src, uint64_t length) noexcept {
			memcpy_decomp::memcpy_decomp(dst, src, length);
		}
	};

	template<uint64_t max_bytes> struct memcpy_decomp_up_to_copier {
		BNCH_SWT_HOST static void impl(std::byte* __restrict dst, const std::byte* __restrict src, uint64_t length) noexcept {
			memcpy_decomp::memcpy_decomp_up_to<max_bytes>(dst, src, length);
		}
	};

	inline constexpr uint64_t guard_bytes{ 64 };
	inline constexpr uint64_t max_offset{ 32 };
	inline constexpr std::byte dst_fill{ 0xCD };

	struct copy_fixture {
		std::vector<std::byte> src;
		std::vector<std::byte> dst;

		explicit copy_fixture(uint64_t length) : src(length + max_offset + 2 * guard_bytes), dst(src.size()) {
			for (uint64_t x = 0; x < src.size(); ++x) {
				src[x] = static_cast<std::byte>((x * 131u + 7u) ^ (x >> 8));
			}
		}

		bool verify(uint64_t length, uint64_t src_offset, uint64_t dst_offset) const {
			const uint64_t dst_begin = guard_bytes + dst_offset;
			const uint64_t dst_end	 = dst_begin + length;
			for (uint64_t x = 0; x < dst.size(); ++x) {
				const bool inside		 = x >= dst_begin && x < dst_end;
				const std::byte expected = inside ? src[guard_bytes + src_offset + (x - dst_begin)] : dst_fill;
				if (dst[x] != expected) {
					std::cout << "MISMATCH length=" << length << " src_offset=" << src_offset << " dst_offset=" << dst_offset << " index=" << x
							  << (inside ? " (inside copy)" : " (guard clobbered)") << " expected=" << std::to_integer<uint32_t>(expected)
							  << " actual=" << std::to_integer<uint32_t>(dst[x]) << std::endl;
					return false;
				}
			}
			return true;
		}
	};

	template<typename copier_type> bool sweep_lengths(uint64_t max_length) {
		for (uint64_t length = 0; length <= max_length; ++length) {
			copy_fixture fixture{ length };
			for (uint64_t src_offset = 0; src_offset < max_offset; ++src_offset) {
				for (uint64_t dst_offset = 0; dst_offset < max_offset; ++dst_offset) {
					std::fill(fixture.dst.begin(), fixture.dst.end(), dst_fill);
					copier_type::impl(fixture.dst.data() + guard_bytes + dst_offset, fixture.src.data() + guard_bytes + src_offset, length);
					if (!fixture.verify(length, src_offset, dst_offset)) {
						return false;
					}
				}
			}
		}
		return true;
	}

	template<uint64_t... max_bytes> bool sweep_up_to_all() {
		return (sweep_lengths<memcpy_decomp_up_to_copier<max_bytes>>(max_bytes) && ...);
	}

	void run_correctness_sweeps() {
		rt_ut::unit_test<"memcpy-decomp-exhaustive-sweep">::assert_eq(true, [] {
			return sweep_lengths<memcpy_decomp_copier>(300);
		});

		rt_ut::unit_test<"memcpy-decomp-up-to-exhaustive-sweep">::assert_eq(true, [] {
			return sweep_up_to_all<0, 1, 2, 3, 4, 7, 8, 15, 16, 17, 31, 32, 33, 63, 64, 65, 127, 128, 129, 255, 256, 257>();
		});
	}

	inline constexpr uint64_t branch_copies_per_iteration{ 4096 };
	inline constexpr uint64_t branch_buffer_bytes{ 1 << 16 };
	inline constexpr uint64_t branch_buffer_mask{ branch_buffer_bytes - 1 };
	inline constexpr uint64_t branch_buffer_slack{ 2048 };
	inline constexpr uint64_t branch_offset_stride{ 192 };
	inline constexpr uint64_t branch_offset_alignment_mask{ ~uint64_t{ 255 } };
	inline constexpr uint64_t branch_length_table_size{ 1 << 16 };
	inline constexpr uint64_t branch_length_table_mask{ branch_length_table_size - 1 };
	inline constexpr uint64_t branch_sequence_step{ 12347 };
	inline volatile uint64_t branch_runtime_size_source{};
	inline uint64_t branch_sequence_base{};

	template<uint64_t min_length, uint64_t max_length> std::array<uint16_t, branch_length_table_size> make_branch_length_table() {
		std::array<uint16_t, branch_length_table_size> table{};
		uint64_t state{ 0x9E3779B97F4A7C15ull };
		for (uint64_t x = 0; x < branch_length_table_size; ++x) {
			state	 = state * 6364136223846793005ull + 1442695040888963407ull;
			table[x] = static_cast<uint16_t>(min_length + (state >> 33) % (max_length - min_length + 1));
		}
		return table;
	}

	template<uint64_t min_length, uint64_t max_length>
	inline const std::array<uint16_t, branch_length_table_size> branch_length_table{ make_branch_length_table<min_length, max_length>() };

	template<typename copier_type, uint64_t min_length, uint64_t max_length> BNCH_SWT_HOST uint64_t run_branch_copies(std::byte* dst, const std::byte* src, uint64_t base) {
		uint64_t bytes_copied{};
		for (uint64_t x = 0; x < branch_copies_per_iteration; ++x) {
			const uint64_t offset = (x * branch_offset_stride) & branch_buffer_mask & branch_offset_alignment_mask;
			const uint64_t length = branch_length_table<min_length, max_length>[(base + x) & branch_length_table_mask] + branch_runtime_size_source;
			copier_type::impl(dst + offset + ((x * 11 + 3) & 63), src + offset + ((x * 5) & 63), length);
			bytes_copied += length;
		}
		return bytes_copied;
	}

	template<typename copier_type, uint64_t min_length, uint64_t max_length> struct branch_workload_type {
		BNCH_SWT_HOST static uint64_t impl(std::vector<std::byte>& dst, const std::vector<std::byte>& src) {
			branch_sequence_base += branch_sequence_step;
			const uint64_t bytes_copied = run_branch_copies<copier_type, min_length, max_length>(dst.data(), src.data(), branch_sequence_base);
			benchmarksuite::do_not_optimize_away(dst.data());
			return bytes_copied;
		}
	};

	template<typename copier_type_new, uint64_t min_length_new, uint64_t max_length_new> struct branch_case {
		using copier_type = copier_type_new;
		static constexpr uint64_t min_length{ min_length_new };
		static constexpr uint64_t max_length{ max_length_new };
	};

	inline constexpr benchmarksuite::string_literal current_path{ benchmarksuite::get_current_path_impl() };
	inline constexpr benchmarksuite::string_literal base_path{ BASE_PATH };
	inline constexpr benchmarksuite::string_literal markdown_path{ base_path + "/Results" };
	inline constexpr benchmarksuite::string_literal csv_path{ base_path + "/csv" };
	inline constexpr benchmarksuite::string_literal json_path{ base_path + "/example-data" };
	inline constexpr benchmarksuite::string_literal graphs_path{ base_path + "/graphs/" };
	inline constexpr benchmarksuite::string_literal markdown_out_path{ markdown_path + "/" + current_path };
	inline constexpr benchmarksuite::string_literal csv_out_path{ csv_path + "/" + current_path };
	inline constexpr benchmarksuite::string_literal json_out_path{ json_path + "/" + current_path };
	inline constexpr benchmarksuite::string_literal graphs_out_path{ graphs_path + "/" + current_path };

	consteval auto make_section00() {
		using system_info = benchmarksuite::system_info_data<benchmarksuite::benchmark_types::cpu>;
		constexpr benchmarksuite::string_literal os_id{ system_info::os_id };
		constexpr benchmarksuite::string_literal os_version{ system_info::os_version };
		constexpr benchmarksuite::string_literal compiler_id{ system_info::compiler_id };
		constexpr benchmarksuite::string_literal compiler_version{ system_info::compiler_version };
		return benchmarksuite::string_literal{ "# memcpy Decomposition\nPerformance profiling of functions (Compiled and run on " + os_id + " " + os_version + " using the " +
			compiler_id + " " + compiler_version + " compiler).  \n\nLatest Results: (" };
	}

	std::string make_section01() {
		return std::format(
			"\n> Adaptive sampling on ({0}): iterations begin at {1} and double each epoch (e.g. {1} → {2} → {3} → ...) up to a per-test-size maximum "
			"(scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to "
			"average out timing noise). "
			"Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, {4}) samples, capped at {5}. "
			"Sampling does not stop early: epochs continue until {6} seconds have elapsed or the iteration cap is reached. "
			"The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), "
			"and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that "
			"retained epoch has RSE <= {7}% AND mean shift <= {8}%; "
			"non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds "
			"should be read with its reduced statistical confidence in mind. "
			"All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.\n\n"
			"#### Note:\n This is the commit of BenchmarkSuite that was used to generate these results: [{9}](https://github.com/nihilai-collective/benchmarksuite/commit/{9}).\n ",
			benchmarksuite::system_info_data<benchmarksuite::benchmark_types::cpu>::device_name(), config.measured_iteration_count, config.measured_iteration_count * 2,
			config.measured_iteration_count * 4, config.min_k, config.max_k, config.max_time_in_s, config.rse_threshold, config.convergence_threshold, BNCH_SWT_COMMIT);
	}

	template<benchmarksuite::string_literal test_name_new, benchmarksuite::string_literal current_path_new> consteval auto generate_section() {
		constexpr benchmarksuite::string_literal test_name_encoded{ benchmarksuite::url_encode_literal<test_name_new>() };
		return "\n----\n### " + test_name_new + " Results \n\n<p align=\"left\"><a href=\"./graphs/" + current_path_new + "/" + test_name_encoded +
			"-Results.png\" target=\"_blank\"><img src=\"./graphs/" + current_path_new + "/" + test_name_encoded + "-Results.png?raw=true\" \nalt=\"\" width=\"400\"/></a></p>\n\n";
	}

	template<typename bench_stage_type, benchmarksuite::string_literal test_name, benchmarksuite::string_literal library_name, benchmarksuite::stage_config_data per_test_config,
		typename functor_type, typename... arg_types>
	void run_benchmark_scaled(arg_types&&... args) {
		auto& test_data_val		= bench_stage_type::get_raw_test_data().get_or_create(test_name.operator std::string_view());
		test_data_val.test_name = test_name.operator std::string_view();
		if constexpr (per_test_config.clear_cpu_caches_before_iterations) {
			benchmarksuite::internal::cache_clearer<per_test_config.benchmark_type> cclearer{};
			cclearer.evict_caches();
		}
		test_data_val.results[library_name.operator std::string_view()] =
			benchmarksuite::internal::run_adaptive_benchmark<functor_type, per_test_config>(std::forward<arg_types>(args)...);
	}

	template<benchmarksuite::string_literal library_name, benchmarksuite::string_literal stage_name, benchmarksuite::string_literal test_name>
	void assert_replay_matches(const std::vector<std::byte>& dst_contender, const std::vector<std::byte>& dst_std) {
		rt_ut::unit_test<"memcpy-decomp-workload-replay">::assert_eq(true, [&] {
			if (dst_contender != dst_std) {
				std::cout << library_name.operator std::string_view() << " diverged from std::memcpy on " << stage_name.operator std::string_view() << "/"
						  << test_name.operator std::string_view() << std::endl;
				return false;
			}
			return true;
		});
	}

	template<typename bench_stage_type, benchmarksuite::string_literal stage_name, benchmarksuite::string_literal test_name>
	void save_test_results(std::string& results_string, const std::string& example_data) {
		auto results = bench_stage_type::get_test_results(test_name.operator std::string());
		results.print(false);
		if (results.size() > 0) {
			static constexpr auto section{ generate_section<test_name, current_path + "/" + stage_name>() };
			results_string += section.operator std::string_view();
			results_string += results.to_markdown(false, false);
			benchmarksuite::file_handle::save_file(results.to_csv(false),
				csv_out_path.operator std::string() + "/" + stage_name.operator std::string() + "/" + test_name.operator std::string() + ".csv");
			benchmarksuite::file_handle::save_file(example_data,
				json_out_path.operator std::string() + "/" + stage_name.operator std::string() + "/" + test_name.operator std::string() + ".json");
		}
	}

	template<typename bench_stage_type, benchmarksuite::string_literal stage_name> void save_stage_results(const std::string& results_string) {
		auto results = bench_stage_type::get_all_results();
		std::string header{ make_section00().operator std::string() + benchmarksuite::get_time() + ")\n" + make_section01() };
		benchmarksuite::file_handle::save_file(header + results_string,
			base_path.operator std::string() + "/" + current_path.operator std::string() + "-" + stage_name.operator std::string() + ".md");
		benchmarksuite::file_handle::save_file(results.to_csv(), csv_out_path.operator std::string() + "/" + stage_name.operator std::string() + "/Results.csv");
		benchmarksuite::execute_python_script(base_path.operator std::string() + "/GenerateGraphs.py",
			csv_out_path.operator std::string() + "/" + stage_name.operator std::string() + "/", graphs_out_path.operator std::string() + "/" + stage_name.operator std::string());
	}

	template<typename bench_stage_type, benchmarksuite::string_literal stage_name, benchmarksuite::string_literal library_name, typename copier_type, uint64_t min_length,
		uint64_t max_length>
	void branch_workload_case(std::string& results_string) {
		static constexpr benchmarksuite::stage_config_data per_count_config{ config_for<branch_copies_per_iteration>() };
		static constexpr benchmarksuite::string_literal count_literal{ benchmarksuite::internal::to_string_literal<branch_copies_per_iteration>() };
		static constexpr benchmarksuite::string_literal min_literal{ benchmarksuite::internal::to_string_literal<min_length>() };
		static constexpr benchmarksuite::string_literal max_literal{ benchmarksuite::internal::to_string_literal<max_length>() };
		static constexpr auto test_name{ "copy_count[" + count_literal + "]-length[" + min_literal + "-" + max_literal + "]" };
		std::vector<std::byte> src(branch_buffer_bytes + branch_buffer_slack);
		for (uint64_t x = 0; x < src.size(); ++x) {
			src[x] = static_cast<std::byte>((x * 131u + 7u) ^ (x >> 8));
		}
		std::vector<std::byte> dst_std(src.size());
		std::vector<std::byte> dst_contender(src.size());

		for (uint64_t x = 1; x <= 16; ++x) {
			run_branch_copies<std_memcpy_copier, min_length, max_length>(dst_std.data(), src.data(), x * branch_sequence_step);
			run_branch_copies<copier_type, min_length, max_length>(dst_contender.data(), src.data(), x * branch_sequence_step);
		}
		assert_replay_matches<library_name, stage_name, test_name>(dst_contender, dst_std);

		run_benchmark_scaled<bench_stage_type, test_name, "std_memcpy", per_count_config, branch_workload_type<std_memcpy_copier, min_length, max_length>>(dst_std, src);
		run_benchmark_scaled<bench_stage_type, test_name, library_name, per_count_config, branch_workload_type<copier_type, min_length, max_length>>(dst_contender, src);

		std::stringstream stream{};
		stream << "[";
		for (uint64_t x = 0; x < branch_copies_per_iteration; ++x) {
			stream << branch_length_table<min_length, max_length>[(branch_sequence_step + x) & branch_length_table_mask];
			if (x < branch_copies_per_iteration - 1) {
				stream << ",";
			}
		}
		stream << "]";
		save_test_results<bench_stage_type, stage_name, test_name>(results_string, stream.str());
	}

	template<benchmarksuite::string_literal stage_name, benchmarksuite::string_literal library_name, typename... case_types> void branch_workload_stage() {
		using benchmark_type = benchmarksuite::benchmark_stage<stage_name, config>;
		std::string results_string{};
		(branch_workload_case<benchmark_type, stage_name, library_name, typename case_types::copier_type, case_types::min_length, case_types::max_length>(results_string), ...);
		save_stage_results<benchmark_type, stage_name>(results_string);
	}

}

int main() {
	benchmarksuite::pin_for_benchmark();
	memcpy_decomp_bench::run_correctness_sweeps();
	using memcpy_decomp_bench::memcpy_decomp_up_to_copier;
	using memcpy_decomp_bench::memcpy_decomp_copier;
	using memcpy_decomp_bench::branch_case;
	memcpy_decomp_bench::branch_workload_stage<"branch-decomp", "memcpy_decomp", branch_case<memcpy_decomp_copier, 1, 15>, branch_case<memcpy_decomp_copier, 1, 16>,
		branch_case<memcpy_decomp_copier, 1, 17>, branch_case<memcpy_decomp_copier, 1, 31>, branch_case<memcpy_decomp_copier, 1, 32>, branch_case<memcpy_decomp_copier, 1, 33>,
		branch_case<memcpy_decomp_copier, 1, 63>, branch_case<memcpy_decomp_copier, 1, 64>, branch_case<memcpy_decomp_copier, 1, 65>, branch_case<memcpy_decomp_copier, 1, 127>,
		branch_case<memcpy_decomp_copier, 1, 128>, branch_case<memcpy_decomp_copier, 1, 129>>();
	memcpy_decomp_bench::branch_workload_stage<"branch-up-to", "memcpy_decomp_up_to", branch_case<memcpy_decomp_up_to_copier<15>, 1, 15>,
		branch_case<memcpy_decomp_up_to_copier<16>, 1, 16>, branch_case<memcpy_decomp_up_to_copier<17>, 1, 17>, branch_case<memcpy_decomp_up_to_copier<31>, 1, 31>,
		branch_case<memcpy_decomp_up_to_copier<32>, 1, 32>, branch_case<memcpy_decomp_up_to_copier<33>, 1, 33>, branch_case<memcpy_decomp_up_to_copier<63>, 1, 63>,
		branch_case<memcpy_decomp_up_to_copier<64>, 1, 64>, branch_case<memcpy_decomp_up_to_copier<65>, 1, 65>, branch_case<memcpy_decomp_up_to_copier<127>, 1, 127>,
		branch_case<memcpy_decomp_up_to_copier<128>, 1, 128>, branch_case<memcpy_decomp_up_to_copier<129>, 1, 129>>();
	return 0;
}
