# memcpy-decomp
Decomposing memcpy into constexpr-known power-of-2-memcpies.

A runtime-length `memcpy` is dispatched on `std::bit_width(length)` into a power-of-2 bucket, and every bucket is copied with exactly two overlapping, compile-time-sized copies: one anchored at the front, one anchored at the back. Because the size of every individual copy is a constant, each one lowers to plain register loads/stores instead of a call into the C runtime. Buckets wider than the target's vector register are split into register-width chunks.

| length | bucket | copies (AVX2) |
|---|---|---|
| 0 | - | nothing |
| 1 | - | one byte |
| 2-3 | 2 | `[0,2)` + `[n-2,n)` |
| 4-7 | 4 | `[0,4)` + `[n-4,n)` |
| 8-15 | 8 | `[0,8)` + `[n-8,n)` |
| 16-31 | 16 | `[0,16)` + `[n-16,n)` |
| 32-63 | 32 | `[0,32)` + `[n-32,n)` |
| 64-127 | 64 | `[0,32)` `[32,64)` + `[n-64,n-32)` `[n-32,n)` |
| 128+ | - | `std::memcpy` |

`memcpy_decomp_up_to<max_bytes>` takes a compile-time upper bound on the length and prunes every bucket above it, so the dispatch only contains the cases that can actually occur.

```cpp
#include "memcpy-decomp.hpp"

memcpy_decomp::memcpy_decomp(dst, src, length);
memcpy_decomp::memcpy_decomp_up_to<64>(dst, src, length);
```

Here's a few benchmarks on a few common operating system/compiler platforms. Although feel free to try it out on more and let me know if you do/what scores you get! Cheers!. Also I will add some instructions for building below.

### The Libraries
- [memcpy-decomp](https://github.com/nihilai-collective/memcpy-decomp)
- std::memcpy

### By OS/Compiler:
----
#### Note:
Examples of some of the data that was used in these tests is available [here](./example-data)

#### Linux/Clang:
----
![Linux/Clang](https://img.shields.io/github/actions/workflow/status/nihilai-collective/memcpy-decomp/Benchmark.yml?style=plastic&logo=linux&logoColor=green&label=Clang&labelColor=pewter&color=blue&branch=benchmarking-newer)

- [memcpy_decomp vs std::memcpy](./Linux-Clang-branch-decomp.md)
- [memcpy_decomp_up_to vs std::memcpy](./Linux-Clang-branch-up-to.md)

#### Linux/GCC:
----
![Linux/GCC](https://img.shields.io/github/actions/workflow/status/nihilai-collective/memcpy-decomp/Benchmark.yml?style=plastic&logo=linux&logoColor=green&label=GCC&labelColor=pewter&color=blue&branch=benchmarking-newer)

- [memcpy_decomp vs std::memcpy](./Linux-GCC-branch-decomp.md)
- [memcpy_decomp_up_to vs std::memcpy](./Linux-GCC-branch-up-to.md)

#### Windows/MSVC:
----
![Windows/MSVC](https://img.shields.io/github/actions/workflow/status/nihilai-collective/memcpy-decomp/Benchmark.yml?style=plastic&logo=Microsoft&logoColor=green&label=MSVC&labelColor=pewter&color=blue&branch=benchmarking-newer)

- [memcpy_decomp vs std::memcpy](./Windows-MSVC-branch-decomp.md)
- [memcpy_decomp_up_to vs std::memcpy](./Windows-MSVC-branch-up-to.md)

#### macOS/Clang:
----
![macOS/Clang](https://img.shields.io/github/actions/workflow/status/nihilai-collective/memcpy-decomp/Benchmark.yml?style=plastic&logo=apple&logoColor=green&label=Clang&labelColor=pewter&color=blue&branch=benchmarking-newer)

- [memcpy_decomp vs std::memcpy](./macOS-Clang-branch-decomp.md)
- [memcpy_decomp_up_to vs std::memcpy](./macOS-Clang-branch-up-to.md)

#### macOS/GCC:
----
![macOS/GCC](https://img.shields.io/github/actions/workflow/status/nihilai-collective/memcpy-decomp/Benchmark.yml?style=plastic&logo=apple&logoColor=green&label=GCC&labelColor=pewter&color=blue&branch=benchmarking-newer)

- [memcpy_decomp vs std::memcpy](./macOS-GCC-branch-decomp.md)
- [memcpy_decomp_up_to vs std::memcpy](./macOS-GCC-branch-up-to.md)

### Pre-requisites:
---
1. CMake 3.31 or later.
2. A C++20 compliant compiler.
3. Python3 and Seaborn for generating the graphs.

### Build Instructions:
---
1. Clone the repo.
2. Cd into the repo's folder and enter `cmake -S . -B ./Build -DCMAKE_BUILD_TYPE=RELEASE_OR_DEBUG -DCMAKE_CXX_COMPILER=PATH_TO_COMPILER_EXECUTABLE` (NOTE: Optionally set a manual installation path by setting `-DCMAKE_INSTALL_PREFIX=CUSTOM_INSTALLATION_PATH`)
3. Then enter `cmake --build ./Build --config=RELEASE_OR_DEBUG`
4. Then enter `cmake --install ./Build`
5. Run the executable from wherever it was installed to!

#### Note:
These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/nihilai-collective/benchmarksuite)

> *"Anytime someone comes to you with one benchmark? They have gamed that benchmark."*  
> — Matt Kulukundis, CppCon 2017: "Designing a Fast, Efficient, Cache-friendly Hash Table, Step by Step"
