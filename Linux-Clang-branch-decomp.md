# memcpy Decomposition
Performance profiling of functions (Compiled and run on Linux 7.0.0-1017-azure using the Clang 24.0.0 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (AMD EPYC 7763 64-Core Processor-AVX2): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1373.26 | 0.439856 | 221.368ms | 32770 | 384 | 3.84765e+06 | 22757.3 | 0.352233 | 1.69548 | 1(Win) | true |
| std_memcpy | 909.685 | 0.252097 | 337.911ms | 32775 | 384 | 2.88121e+06 | 34360.1 | 0.310388 | 2.56087 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1438.52 | 0.321788 | 225.86ms | 34770 | 384 | 2.11273e+06 | 23050.8 | 0.140456 | 1.61871 | 1(Win) | true |
| std_memcpy | 942.323 | 0.36082 | 344.689ms | 34760 | 192 | 3.0935e+06 | 35179.1 | 0.171041 | 2.47232 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 1497.35 | 0.40029 | 230.02ms | 36824 | 214 | 1.88615e+06 | 23453.4 | 0.575986 | 1.55518 | 1(Win) | true |
| std_memcpy | 983.489 | 0.238012 | 349.276ms | 36803 | 384 | 2.77047e+06 | 35687.1 | 0.0371055 | 2.36887 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2365.03 | 0.277857 | 258.705ms | 65549 | 384 | 2.07127e+06 | 26432.1 | 0.0414066 | 0.984752 | 1(Win) | true |
| std_memcpy | 1665.84 | 0.317057 | 366.471ms | 65576 | 384 | 5.44045e+06 | 37541.7 | 0.23166 | 1.39854 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2388.2 | 0.345653 | 265.384ms | 67732 | 384 | 3.35628e+06 | 27047.2 | 0.191676 | 0.975233 | 1(Win) | true |
| std_memcpy | 1723.08 | 0.229703 | 366.989ms | 67718 | 384 | 2.84619e+06 | 37480 | 0.138812 | 1.35215 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 2423.2 | 0.363163 | 268.109ms | 69796 | 384 | 3.82141e+06 | 27469.1 | 0.401764 | 0.96116 | 1(Win) | true |
| std_memcpy | 1777.89 | 0.256182 | 366.502ms | 69831 | 384 | 3.53603e+06 | 37457.9 | 0.094431 | 1.31045 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 5055.93 | 0.444267 | 243.261ms | 131792 | 214 | 2.61022e+06 | 24859.2 | 0.0787618 | 0.460598 | 1(Win) | true |
| std_memcpy | 3355.93 | 0.347018 | 366.678ms | 131764 | 214 | 3.61315e+06 | 37444.2 | 0.0268272 | 0.694256 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 4967.68 | 0.573744 | 250.221ms | 133044 | 214 | 4.59548e+06 | 25541.2 | 0.00223067 | 0.468795 | 1(Win) | true |
| std_memcpy | 3373.2 | 0.248893 | 367.391ms | 133023 | 384 | 3.36455e+06 | 37608.5 | 0.0821425 | 0.690687 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 5006.04 | 0.280406 | 252.088ms | 135092 | 384 | 1.99975e+06 | 25735.7 | 0.0717844 | 0.465198 | 1(Win) | true |
| std_memcpy | 3378.58 | 0.308409 | 372.786ms | 135108 | 384 | 5.31229e+06 | 38137.2 | 0.247197 | 0.689606 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 8582.3 | 0.309465 | 284.109ms | 261120 | 384 | 3.09619e+06 | 29015.9 | 0.122263 | 0.271389 | 1(Win) | true |
| std_memcpy | 7027.07 | 0.249549 | 346.91ms | 261140 | 384 | 3.00359e+06 | 35440.4 | 0.0467184 | 0.331533 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 8602.63 | 0.280414 | 286.359ms | 263164 | 384 | 2.56992e+06 | 29173.9 | 0.317774 | 0.270754 | 1(Win) | true |
| std_memcpy | 7091.83 | 0.342625 | 346.429ms | 263076 | 214 | 3.14411e+06 | 35377.1 | 0.0437167 | 0.328493 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/Linux-Clang/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp | 8629.11 | 0.433357 | 287.121ms | 265557 | 214 | 3.46171e+06 | 29348.9 | 0.0880618 | 0.26992 | 1(Win) | true |
| std_memcpy | 7144.47 | 0.274862 | 346.095ms | 265467 | 384 | 3.64286e+06 | 35435.7 | 0.0446136 | 0.326076 | 2(Loss) | true |
