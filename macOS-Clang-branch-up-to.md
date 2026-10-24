# memcpy Decomposition
Performance profiling of functions (Compiled and run on macOS 25.6.0 using the Clang 23.1.4 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (Apple M1 (Virtual)-NEON): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 1689.77 | 0.830432 | 176.385ms | 32786 | 96 | 2.26679e+06 | 18504 | 0.663499 | 1(Win) | true |
| std_memcpy | 736.069 | 0.0857001 | 423.085ms | 32759 | 30 | 39691.4 | 42443 | 0.0067537 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 1509.6 | 1.42439 | 212.316ms | 34763 | 30 | 2.93556e+06 | 21961.1 | 1.20607 | 1(Win) | true |
| std_memcpy | 692.232 | 0.794857 | 452.304ms | 34772 | 214 | 3.10283e+07 | 47905.2 | 0.0848203 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 1728.76 | 0.50152 | 210.143ms | 36810 | 192 | 1.99133e+06 | 20306.4 | 0.934167 | 1(Win) | true |
| std_memcpy | 733.593 | 0.478449 | 476.481ms | 36825 | 214 | 1.12267e+07 | 47872.3 | 0.152149 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 3319.74 | 0.90704 | 201.362ms | 65600 | 96 | 2.80491e+06 | 18845.1 | 1.32006 | 1(Win) | true |
| std_memcpy | 1174.55 | 0.837335 | 554.476ms | 65546 | 96 | 1.90643e+07 | 53220 | 2.63411 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 2623.57 | 1.75744 | 267.541ms | 67755 | 30 | 5.62053e+06 | 24629.1 | 2.57155 | 1(Win) | true |
| std_memcpy | 1027.34 | 2.66248 | 620.274ms | 67715 | 30 | 8.40304e+07 | 62859.6 | 0.536509 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to DID NOT CONVERGE | 2812.76 | 0.920641 | 297.193ms | 69827 | 96 | 4.56067e+06 | 23674.9 | 8.66511 | -(Win) | false |
| std_memcpy | 1239.59 | 1.90055 | 579.204ms | 69790 | 30 | 3.12403e+07 | 53693.1 | 0.401722 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 5788.29 | 0.711658 | 236.274ms | 131737 | 96 | 2.29048e+06 | 21704.8 | 0.203951 | 1(Win) | true |
| std_memcpy | 1971.97 | 0.800768 | 645.846ms | 131697 | 96 | 2.49712e+07 | 63690.9 | 2.42181 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 3819.42 | 3.57053 | 298.185ms | 133033 | 214 | 3.01025e+08 | 33217.1 | 4.1055 | 1(Win) | true |
| std_memcpy DID NOT CONVERGE | 2043.31 | 1.24565 | 766.222ms | 133059 | 384 | 2.29793e+08 | 62102.3 | 11.9509 | -(Loss) | false |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to DID NOT CONVERGE | 4790.72 | 3.36249 | 281.048ms | 135101 | 384 | 3.14027e+08 | 26894.1 | 5.59186 | -(Win) | false |
| std_memcpy | 1689.38 | 1.65298 | 700.727ms | 135115 | 214 | 3.40175e+08 | 76274.1 | 0.553593 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 11575 | 1.52248 | 222.008ms | 260987 | 30 | 3.21529e+06 | 21502.9 | 1.4693 | 1(Win) | true |
| std_memcpy | 4556.6 | 0.704074 | 549.198ms | 261099 | 96 | 1.42114e+07 | 54646.7 | 0.300898 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 10823.2 | 0.580536 | 281.146ms | 263185 | 384 | 6.9599e+06 | 23190.3 | 1.95497 | 1(Win) | true |
| std_memcpy | 4721.6 | 0.381014 | 564.412ms | 263163 | 192 | 7.87508e+06 | 53154.1 | 1.70249 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/macOS-Clang/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 10550.7 | 0.912729 | 236.733ms | 265407 | 96 | 4.60275e+06 | 23990.1 | 0.929692 | 1(Win) | true |
| std_memcpy DID NOT CONVERGE | 4628.63 | 1.16782 | 584.195ms | 265842 | 30 | 1.22748e+07 | 54773.7 | 10.2626 | -(Loss) | false |
