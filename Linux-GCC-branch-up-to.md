# memcpy Decomposition
Performance profiling of functions (Compiled and run on Linux 7.0.0-1017-azure using the GCC 16.0.1 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (AMD EPYC 9V74 80-Core Processor-AVX512): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1778.89 | 0.463871 | 171.93ms | 32780 | 214 | 1.42206e+06 | 17573.4 | 0.103847 | 1.3895 | 1(Win) | true |
| std_memcpy | 1045.55 | 0.214935 | 293.047ms | 32768 | 384 | 1.58472e+06 | 29888.4 | 0.261808 | 2.36565 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1642.59 | 0.23408 | 197.654ms | 34765 | 384 | 857189 | 20184.1 | 0.0384372 | 1.50502 | 1(Win) | true |
| std_memcpy | 1106.98 | 0.274716 | 292.696ms | 34772 | 214 | 1.44935e+06 | 29956.9 | 0.1321 | 2.23424 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1684.57 | 0.314243 | 203.798ms | 36796 | 214 | 916991 | 20831 | 0.19196 | 1.46766 | 1(Win) | true |
| std_memcpy | 1164.9 | 0.357098 | 295.055ms | 36802 | 192 | 2.22252e+06 | 30129 | 0.0970748 | 2.12331 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 3221.62 | 0.347036 | 190.213ms | 65575 | 384 | 1.74261e+06 | 19411.6 | 0.269501 | 0.767341 | 1(Win) | true |
| std_memcpy | 2021.54 | 0.26783 | 302.045ms | 65553 | 214 | 1.46807e+06 | 30924.9 | 0.0753449 | 1.2235 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2828.98 | 0.319843 | 223.663ms | 67732 | 192 | 1.024e+06 | 22833 | 0.0853297 | 0.87406 | 1(Win) | true |
| std_memcpy | 2057.76 | 0.35648 | 307.044ms | 67712 | 192 | 2.40279e+06 | 31381.4 | 0.137428 | 1.20195 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2794.02 | 0.314201 | 233.091ms | 69826 | 384 | 2.15342e+06 | 23833.7 | 0.0277782 | 0.885039 | 1(Win) | true |
| std_memcpy | 2131.65 | 0.336834 | 305.765ms | 69824 | 214 | 2.36931e+06 | 31238.4 | 0.0325401 | 1.16032 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 5879.03 | 0.219807 | 209.226ms | 131679 | 384 | 846521 | 21360.5 | 0.107999 | 0.420556 | 1(Win) | true |
| std_memcpy | 3991.05 | 0.272473 | 307.813ms | 131725 | 192 | 1.41225e+06 | 31476.2 | 0.116195 | 0.619696 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 5329.83 | 0.27461 | 233.111ms | 133033 | 214 | 914400 | 23803.7 | 0.0164566 | 0.463966 | 1(Win) | true |
| std_memcpy | 3963.98 | 0.242204 | 313.169ms | 133059 | 384 | 2.30843e+06 | 32011.9 | 0.0271457 | 0.62397 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 5344.09 | 0.324372 | 236.313ms | 135101 | 384 | 2.34847e+06 | 24109.2 | 0.0532664 | 0.462716 | 1(Win) | true |
| std_memcpy | 4039.23 | 0.373891 | 312.067ms | 135103 | 96 | 1.36551e+06 | 31898.2 | 0.174014 | 0.612336 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 10687.3 | 0.206456 | 228.232ms | 261107 | 384 | 888554 | 23299.6 | 0.0281131 | 0.231369 | 1(Win) | true |
| std_memcpy | 7759.09 | 0.238858 | 314.847ms | 261054 | 214 | 1.25699e+06 | 32086.3 | 0.0452312 | 0.318796 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 10493.8 | 0.35455 | 233.7ms | 263185 | 384 | 2.76149e+06 | 23918.2 | 0.0349512 | 0.235646 | 1(Win) | true |
| std_memcpy | 7694.61 | 0.250752 | 319.029ms | 263145 | 384 | 2.56825e+06 | 32614.3 | 0.115641 | 0.321461 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/Linux-GCC/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 10493.9 | 0.390218 | 236.292ms | 265407 | 96 | 850424 | 24119.9 | 0.0175741 | 0.235645 | 1(Win) | true |
| std_memcpy | 7800.71 | 0.178636 | 318.412ms | 265668 | 384 | 1.29265e+06 | 32479.2 | 0.0754001 | 0.317095 | 2(Loss) | true |
