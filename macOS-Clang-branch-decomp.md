# memcpy Decomposition
Performance profiling of functions (Compiled and run on macOS 25.6.0 using the Clang 23.1.4 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (Apple M1 (Virtual)-NEON): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 1550.3 | 0.463543 | 285.031ms | 32806 | 30 | 262526 | 20180.7 | 3.29971 | 1(Win) | true |
| std_memcpy DID NOT CONVERGE | 606.966 | 3.33737 | 619.007ms | 32765 | 30 | 8.8556e+07 | 51480.6 | 8.94213 | -(Loss) | false |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp DID NOT CONVERGE | 1643.27 | 1.15725 | 292.843ms | 34792 | 30 | 1.63803e+06 | 20191.7 | 6.7658 | -(Win) | false |
| std_memcpy | 631.349 | 3.53997 | 631.059ms | 34751 | 30 | 1.03587e+08 | 52491.9 | 0.0877095 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp DID NOT CONVERGE | 1079.3 | 1.48836 | 277.477ms | 36802 | 384 | 8.99517e+07 | 32518.6 | 5.25618 | -(Win) | false |
| std_memcpy DID NOT CONVERGE | 712.12 | 1.74025 | 614.048ms | 36828 | 48 | 3.53604e+07 | 49320.4 | 9.18673 | -(Loss) | false |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 2130.45 | 1.45365 | 322.223ms | 65545 | 96 | 1.74631e+07 | 29340.4 | 3.77737 | 1(Win) | true |
| std_memcpy | 1010.87 | 1.66952 | 675.789ms | 65561 | 214 | 2.28189e+08 | 61851.3 | 1.50444 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 1403.02 | 6.22607 | 372.673ms | 67739 | 192 | 1.57792e+09 | 46044.5 | 1.2422 | 1(Win) | true |
| std_memcpy | 906.247 | 3.11881 | 750.554ms | 67721 | 96 | 4.74247e+08 | 71265.2 | 4.60547 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp DID NOT CONVERGE | 1703.37 | 3.18964 | 375.658ms | 69819 | 192 | 2.98478e+08 | 39089.9 | 18.2069 | -(Win) | false |
| std_memcpy | 823.108 | 0.511182 | 704.811ms | 69805 | 48 | 8.20445e+06 | 80877.6 | 0.531583 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp DID NOT CONVERGE | 4039.02 | 3.04159 | 346.213ms | 131792 | 214 | 1.91707e+08 | 31118 | 16.3985 | -(Win) | false |
| std_memcpy | 1598.64 | 1.86889 | 803.308ms | 131779 | 192 | 4.14442e+08 | 78613.5 | 0.117678 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp DID NOT CONVERGE | 5707.83 | 1.60574 | 318.793ms | 133039 | 96 | 1.22303e+07 | 22228.3 | 5.56565 | -(Win) | false |
| std_memcpy | 1869.4 | 1.7186 | 751.234ms | 133053 | 192 | 2.61274e+08 | 67877 | 3.53604 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 6306.46 | 0.652198 | 216.562ms | 135095 | 96 | 1.70427e+06 | 20429.3 | 2.02924 | 1(Win) | true |
| std_memcpy | 2171.8 | 0.692555 | 691.465ms | 135105 | 96 | 1.62063e+07 | 59326.9 | 0.228434 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 9336.36 | 1.0272 | 287.008ms | 261193 | 214 | 1.60728e+07 | 26679.9 | 2.41615 | 1(Win) | true |
| std_memcpy | 4383.32 | 0.999907 | 575.752ms | 261096 | 96 | 3.09732e+07 | 56806.4 | 0.60587 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 8658.3 | 2.23514 | 284.773ms | 263222 | 214 | 8.98675e+07 | 28992.8 | 3.08982 | 1(Win) | true |
| std_memcpy | 4302.99 | 0.509961 | 597.073ms | 263076 | 214 | 1.89194e+07 | 58305.7 | 2.69802 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 8937.01 | 1.73658 | 263.471ms | 265333 | 30 | 7.25286e+06 | 28313.8 | 0.597249 | 1(Win) | true |
| std_memcpy DID NOT CONVERGE | 3728.65 | 1.4307 | 632.323ms | 265467 | 384 | 3.62365e+08 | 67898.3 | 17.7797 | -(Loss) | false |
