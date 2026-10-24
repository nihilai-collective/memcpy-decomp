# memcpy Decomposition
Performance profiling of functions (Compiled and run on macOS 25.6.0 using the GCC 16.2.0 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (Apple M1 (Virtual)-NEON): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 1935.26 | 0.412263 | 155.769ms | 32774 | 384 | 1.70239e+06 | 16150.7 | 1.53395 | 1(Win) | true |
| std_memcpy | 714.323 | 0.157678 | 428.347ms | 32768 | 384 | 1.82717e+06 | 43747.3 | 0.0045715 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 1850.52 | 0.234674 | 175.52ms | 34762 | 96 | 169675 | 17914.7 | 0.0297619 | 1(Win) | true |
| std_memcpy | 764.077 | 0.171226 | 431.171ms | 34759 | 192 | 1.05949e+06 | 43384 | 0.0430451 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 1892.89 | 0.160022 | 183.778ms | 36819 | 384 | 338360 | 18550 | 0.29026 | 1(Win) | true |
| std_memcpy | 799.606 | 0.355051 | 429.415ms | 36784 | 48 | 1.16466e+06 | 43872 | 0.0534603 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 3496.24 | 0.302215 | 185.289ms | 65573 | 214 | 625311 | 17886.5 | 0.81069 | 1(Win) | true |
| std_memcpy | 1257.16 | 0.185113 | 487.458ms | 65546 | 96 | 813308 | 49722.7 | 0.0536021 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 3244.85 | 0.319741 | 194.781ms | 67732 | 192 | 777847 | 19906.7 | 0.147138 | 1(Win) | true |
| std_memcpy | 1306.99 | 0.111389 | 484.328ms | 67721 | 384 | 1.16336e+06 | 49414 | 0.173737 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 3246.91 | 0.248593 | 200.901ms | 69827 | 96 | 249547 | 20509.3 | 0.453016 | 1(Win) | true |
| std_memcpy | 1346.57 | 0.108302 | 485.684ms | 69826 | 384 | 1.1015e+06 | 49452.7 | 0.0121343 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 6825.95 | 0.268421 | 182.612ms | 131688 | 214 | 521930 | 18398.5 | 0.35548 | 1(Win) | true |
| std_memcpy | 2302.76 | 0.158498 | 536.998ms | 131711 | 214 | 1.59957e+06 | 54547.1 | 0.150456 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 6056.15 | 0.229232 | 205.037ms | 133033 | 214 | 493503 | 20948.9 | 0.189395 | 1(Win) | true |
| std_memcpy | 2342.81 | 0.172516 | 529.35ms | 133059 | 384 | 3.35274e+06 | 54163.3 | 0.0725672 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 6068.67 | 0.220055 | 208.446ms | 135101 | 384 | 838149 | 21230.7 | 0.352934 | 1(Win) | true |
| std_memcpy | 2402.86 | 0.14507 | 547.236ms | 135115 | 214 | 1.29515e+06 | 53626 | 0.641039 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 12237.1 | 0.227339 | 198.085ms | 261193 | 214 | 458278 | 20355.6 | 0.0183923 | 1(Win) | true |
| std_memcpy | 5033.1 | 0.149149 | 485.974ms | 261156 | 192 | 1.04586e+06 | 49484 | 0.0942177 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 12292.3 | 0.484635 | 192.075ms | 263150 | 48 | 469907 | 20416 | 0.270946 | 1(Win) | true |
| std_memcpy | 5056.44 | 0.155623 | 485.742ms | 263145 | 384 | 2.29076e+06 | 49630.7 | 0.144861 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp_up_to | 12696.2 | 0.323412 | 195.253ms | 265407 | 96 | 399080 | 19936 | 0.187617 | 1(Win) | true |
| std_memcpy | 5135.62 | 0.115552 | 484.183ms | 265668 | 384 | 1.24791e+06 | 49334 | 0.0499743 | 2(Loss) | true |
