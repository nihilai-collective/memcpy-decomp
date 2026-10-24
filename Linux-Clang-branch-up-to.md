# memcpy Decomposition
Performance profiling of functions (Compiled and run on Linux 7.0.0-1017-azure using the Clang 24.0.0 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (AMD EPYC 7763 64-Core Processor-AVX2): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1503.66 | 0.497266 | 203.757ms | 32771 | 192 | 2.05102e+06 | 20784.8 | 0.0500416 | 1.54824 | 1(Win) | true |
| std_memcpy | 908.153 | 0.294798 | 336.917ms | 32768 | 384 | 3.95144e+06 | 34410.2 | 0.0352794 | 2.56521 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1491.02 | 0.32987 | 217.577ms | 34765 | 384 | 2.066e+06 | 22236 | 0.158238 | 1.56166 | 1(Win) | true |
| std_memcpy | 943.505 | 0.241847 | 344.783ms | 34773 | 384 | 2.77463e+06 | 35147.7 | 0.24407 | 2.4692 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1501.1 | 0.29614 | 229.867ms | 36819 | 384 | 1.84265e+06 | 23391.6 | 0.141644 | 1.55125 | 1(Win) | true |
| std_memcpy | 984.88 | 0.32028 | 349.316ms | 36825 | 214 | 2.79117e+06 | 35657.9 | 0.0914754 | 2.3655 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2753.29 | 0.442067 | 222.861ms | 65573 | 214 | 2.15745e+06 | 22713 | 0.00787239 | 0.845731 | 1(Win) | true |
| std_memcpy | 1668.66 | 0.344251 | 366.548ms | 65553 | 214 | 3.55968e+06 | 37464.8 | 0.0851013 | 1.39623 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2477.6 | 0.284095 | 255.486ms | 67738 | 384 | 2.10696e+06 | 26073.5 | 0.0252128 | 0.94002 | 1(Win) | true |
| std_memcpy | 1724.89 | 0.332881 | 366.908ms | 67745 | 214 | 3.32672e+06 | 37455.3 | 0.0361268 | 1.35074 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2608.36 | 0.30546 | 249.995ms | 69826 | 384 | 2.3353e+06 | 25530 | 0.0527537 | 0.892845 | 1(Win) | true |
| std_memcpy | 1778.8 | 0.261697 | 366.624ms | 69826 | 384 | 3.6856e+06 | 37436.1 | 0.0279025 | 1.3098 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 5064.62 | 0.46731 | 244.075ms | 131765 | 192 | 2.58117e+06 | 24811.5 | 0.149137 | 0.459825 | 1(Win) | true |
| std_memcpy | 3337.24 | 0.440503 | 366.603ms | 131711 | 214 | 5.88274e+06 | 37638.6 | 0.0936739 | 0.698112 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 4712.73 | 0.378478 | 264.705ms | 133069 | 192 | 1.99428e+06 | 26927.9 | 0.0888545 | 0.494199 | 1(Win) | true |
| std_memcpy | 3370.54 | 0.275522 | 368.04ms | 133059 | 384 | 4.13174e+06 | 37648.2 | 0.15118 | 0.69123 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 4778.22 | 0.278432 | 264.39ms | 135101 | 384 | 2.16447e+06 | 26964.4 | 0.0961584 | 0.487425 | 1(Win) | true |
| std_memcpy | 3391.15 | 0.368412 | 371.991ms | 135110 | 192 | 3.76227e+06 | 37996.3 | 0.170221 | 0.687053 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 9233.54 | 0.429958 | 264.225ms | 261193 | 214 | 2.87907e+06 | 26977 | 0.0362253 | 0.252233 | 1(Win) | true |
| std_memcpy | 7025.85 | 0.324052 | 347.097ms | 261054 | 214 | 2.82166e+06 | 35434.9 | 0.0930291 | 0.331583 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 9133.35 | 0.282675 | 269.214ms | 263185 | 384 | 2.31722e+06 | 27480.9 | 0.0247365 | 0.25501 | 1(Win) | true |
| std_memcpy | 7083.03 | 0.290643 | 346.384ms | 263145 | 384 | 4.07197e+06 | 35430.4 | 0.0587955 | 0.328899 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 9223.45 | 0.286924 | 269.585ms | 265580 | 384 | 2.38379e+06 | 27460.1 | 0.104617 | 0.252508 | 1(Win) | true |
| std_memcpy | 7165.56 | 0.262085 | 346.223ms | 265668 | 384 | 3.29757e+06 | 35358.1 | 0.0353254 | 0.325116 | 2(Loss) | true |
