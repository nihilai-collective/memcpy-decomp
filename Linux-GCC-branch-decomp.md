# memcpy Decomposition
Performance profiling of functions (Compiled and run on Linux 7.0.0-1017-azure using the GCC 16.0.1 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (AMD EPYC 9V74 80-Core Processor-AVX512): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1600.53 | 0.23295 | 191.269ms | 32770 | 384 | 794463 | 19525.8 | 0.14136 | 1.54456 | 1(Win) | true |
| std_memcpy | 1049.81 | 0.318913 | 297.294ms | 32765 | 30 | 270306 | 29764.3 | 0.466718 | 2.356 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1627.59 | 0.300371 | 199.797ms | 34770 | 384 | 1.43802e+06 | 20373.2 | 0.123554 | 1.51897 | 1(Win) | true |
| std_memcpy | 1105.61 | 0.272296 | 292.769ms | 34762 | 384 | 2.55986e+06 | 29984.8 | 0.200921 | 2.23708 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1669.71 | 0.377973 | 205.87ms | 36824 | 214 | 1.35242e+06 | 21032.3 | 0.373747 | 1.48073 | 1(Win) | true |
| std_memcpy | 1167.26 | 0.182858 | 294.335ms | 36803 | 384 | 1.16088e+06 | 30068.7 | 0.0786233 | 2.11896 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2620.15 | 0.438502 | 240.014ms | 65545 | 96 | 1.05059e+06 | 23856.7 | 0.20732 | 0.943697 | 1(Win) | true |
| std_memcpy | 2020.91 | 0.274273 | 302.769ms | 65576 | 384 | 2.76628e+06 | 30945.6 | 0.17989 | 1.22388 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2611.48 | 0.292966 | 242.229ms | 67732 | 384 | 2.01641e+06 | 24734.7 | 0.0240527 | 0.946918 | 1(Win) | true |
| std_memcpy | 2062.66 | 0.305412 | 306.384ms | 67720 | 214 | 1.95688e+06 | 31310.5 | 0.0215497 | 1.19914 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2651.11 | 0.217141 | 245.486ms | 69796 | 384 | 1.14136e+06 | 25107.6 | 0.0441861 | 0.932761 | 1(Win) | true |
| std_memcpy | 2122.93 | 0.34214 | 307.065ms | 69839 | 214 | 2.46577e+06 | 31373.7 | 1.99367e-05 | 1.16509 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 5478.04 | 0.426822 | 223.998ms | 131792 | 214 | 2.05227e+06 | 22943.7 | 0.0235615 | 0.451365 | 1(Win) | true |
| std_memcpy | 4021.88 | 0.370615 | 306.509ms | 131780 | 96 | 1.28752e+06 | 31247.8 | 0.0188382 | 0.614972 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 5401.75 | 0.296249 | 230.197ms | 133035 | 192 | 929569 | 23487.3 | 0.0328971 | 0.457756 | 1(Win) | true |
| std_memcpy | 3967.01 | 0.2325 | 312.654ms | 133023 | 384 | 2.12279e+06 | 31979 | 0.131631 | 0.623495 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 5393.22 | 0.31078 | 233.234ms | 135107 | 192 | 1.05845e+06 | 23890.8 | 0.214644 | 0.458494 | 1(Win) | true |
| std_memcpy | 4033.68 | 0.282038 | 311.896ms | 135108 | 384 | 3.11679e+06 | 31943.4 | 0.124423 | 0.613186 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 9509.6 | 0.288309 | 256.094ms | 261120 | 384 | 2.18877e+06 | 26186.5 | 0.0910171 | 0.260057 | 1(Win) | true |
| std_memcpy | 7755.06 | 0.275604 | 314.371ms | 261083 | 214 | 1.6756e+06 | 32106.5 | 0.0918748 | 0.318955 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 9538.85 | 0.268874 | 257.849ms | 263222 | 214 | 1.07143e+06 | 26316.4 | 0.0696253 | 0.259257 | 1(Win) | true |
| std_memcpy | 7709.32 | 0.245857 | 321.093ms | 263076 | 214 | 1.36997e+06 | 32543.6 | 0.00367821 | 0.32083 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 9520.78 | 0.307064 | 260.486ms | 265494 | 384 | 2.56067e+06 | 26593.9 | 0.0274404 | 0.259751 | 1(Win) | true |
| std_memcpy | 7762.04 | 0.384551 | 318.993ms | 265394 | 214 | 3.36474e+06 | 32607.3 | 0.0933126 | 0.318654 | 2(Loss) | true |
