# memcpy Decomposition
Performance profiling of functions (Compiled and run on Windows 10.0.26100 using the MSVC 19.51.36260.0 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (AMD EPYC 7763 64-Core Processor-AVX2): iterations begin at 60 and double each epoch (e.g. 60 ? 120 ? 240 ? ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1342.16 | 0.541197 | 269.187ms | 32770 | 384 | 6.09791e+06 | 23284.6 | 0.883494 | 1.73481 | 1(Win) | true |
| std_memcpy | 732.222 | 0.457091 | 418.299ms | 32771 | 192 | 7.30806e+06 | 42682.3 | 0.114836 | 3.18244 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1327.45 | 0.110261 | 248.362ms | 34781 | 48 | 36436.2 | 24987.5 | 0.567051 | 1.75477 | 1(Win) | true |
| std_memcpy | 773.732 | 0.467782 | 418.718ms | 34762 | 384 | 1.54257e+07 | 42846.4 | 0.140809 | 3.01153 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1414.22 | 0.39362 | 243.239ms | 36802 | 384 | 3.66437e+06 | 24817.4 | 0.00314789 | 1.6467 | 1(Win) | true |
| std_memcpy | 862.752 | 0.653953 | 396.814ms | 36789 | 214 | 1.51345e+07 | 40665.9 | 0.22014 | 2.7006 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2200.64 | 0.481015 | 278.972ms | 65535 | 214 | 3.99376e+06 | 28400.5 | 0.00439639 | 1.05844 | 1(Win) | true |
| std_memcpy | 1624.17 | 0.465901 | 376.574ms | 65576 | 384 | 1.23581e+07 | 38504.9 | 0.0371838 | 1.43449 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2255.27 | 0.570624 | 280.955ms | 67732 | 384 | 1.0257e+07 | 28641.4 | 0.0717777 | 1.03287 | 1(Win) | true |
| std_memcpy | 1704.24 | 0.342974 | 372.62ms | 67718 | 384 | 6.48634e+06 | 37894.3 | 0.317123 | 1.36704 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2195.44 | 0.393187 | 302.178ms | 69796 | 384 | 5.45698e+06 | 30318.8 | 0.377632 | 1.06109 | 1(Win) | true |
| std_memcpy | 1726.69 | 0.604026 | 392.168ms | 69800 | 192 | 1.04111e+07 | 38551.6 | 0.0688538 | 1.34939 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 4705.67 | 0.159011 | 264.694ms | 131695 | 30 | 54034.5 | 26690 | 0.401254 | 0.495041 | 1(Win) | true |
| std_memcpy | 3502.86 | 0.496554 | 351.208ms | 131700 | 384 | 1.21727e+07 | 35856 | 0.313496 | 0.66508 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 4567.77 | 0.59608 | 272.13ms | 133083 | 384 | 1.05335e+07 | 27785.4 | 0.147865 | 0.509896 | 1(Win) | true |
| std_memcpy | 3368.85 | 0.644663 | 367.915ms | 133096 | 214 | 1.26254e+07 | 37677.6 | 0.0152939 | 0.691591 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 4794.54 | 0.159433 | 266.346ms | 135003 | 30 | 54988.5 | 26853.3 | 0.185851 | 0.485566 | 1(Win) | true |
| std_memcpy | 3349.66 | 0.347744 | 375.658ms | 135108 | 384 | 6.87091e+06 | 38466.4 | 0.170216 | 0.69552 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 8025.7 | 0.136158 | 307.759ms | 261303 | 30 | 53620.7 | 31050 | 0.258314 | 0.290181 | 1(Win) | true |
| std_memcpy | 5337.74 | 0.425714 | 455ms | 261083 | 214 | 8.43903e+06 | 46646.7 | 0.244248 | 0.436509 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 8136.49 | 0.504564 | 302.279ms | 263164 | 384 | 9.30128e+06 | 30845.3 | 0.166886 | 0.28629 | 1(Win) | true |
| std_memcpy | 5352.53 | 0.454436 | 458.465ms | 263172 | 384 | 1.74357e+07 | 46890.1 | 0.0987594 | 0.435408 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 8269.09 | 0.22316 | 304.098ms | 265384 | 30 | 139954 | 30606.7 | 0.273015 | 0.281506 | 1(Win) | true |
| std_memcpy | 5521.04 | 0.609036 | 449.217ms | 265614 | 192 | 1.49916e+07 | 45880.7 | 0.178543 | 0.422068 | 2(Loss) | true |
