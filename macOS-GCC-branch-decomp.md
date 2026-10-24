# memcpy Decomposition
Performance profiling of functions (Compiled and run on macOS 25.6.0 using the GCC 16.2.0 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (Apple M1 (Virtual)-NEON): iterations begin at 60 and double each epoch (e.g. 60 → 120 → 240 → ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 1800.63 | 0.190225 | 172.378ms | 32770 | 384 | 418567 | 17356 | 0.0153622 | 1(Win) | true |
| std_memcpy | 713.382 | 0.26224 | 435.99ms | 32770 | 214 | 2.82438e+06 | 43808.3 | 0.328944 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 1801.58 | 0.283533 | 181.62ms | 34775 | 192 | 523023 | 18408 | 0.101302 | 1(Win) | true |
| std_memcpy | 765.861 | 0.210259 | 425.47ms | 34765 | 96 | 795371 | 43290.7 | 0 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 1888.65 | 0.304226 | 181.912ms | 36802 | 384 | 1.22736e+06 | 18583.3 | 0.0107635 | 1(Win) | true |
| std_memcpy | 801.629 | 0.301825 | 428.472ms | 36828 | 48 | 839390 | 43813.3 | 0.0462783 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 2865.94 | 0.230343 | 223.292ms | 65545 | 96 | 242304 | 21810.7 | 0.474568 | 1(Win) | true |
| std_memcpy | 1257.27 | 0.158874 | 486.662ms | 65576 | 384 | 2.39813e+06 | 49741.3 | 0.435026 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 3132.01 | 0.300062 | 207.087ms | 67723 | 214 | 819334 | 20621.2 | 0.310241 | 1(Win) | true |
| std_memcpy | 1313.21 | 0.117881 | 485.415ms | 67711 | 48 | 161284 | 49173.3 | 0.112671 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 3174.1 | 0.192506 | 207.603ms | 69796 | 384 | 625815 | 20970.7 | 0.190379 | 1(Win) | true |
| std_memcpy | 1344.49 | 0.127793 | 485.216ms | 69839 | 214 | 857654 | 49538.4 | 0.209824 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 6256.66 | 0.232633 | 199.346ms | 131754 | 96 | 209536 | 20082.7 | 0.520555 | 1(Win) | true |
| std_memcpy | 2308.84 | 0.135255 | 535.869ms | 131779 | 192 | 1.04068e+06 | 54432 | 0.122627 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 6732.51 | 0.247776 | 190.033ms | 133044 | 214 | 466622 | 18845.9 | 0.572292 | 1(Win) | true |
| std_memcpy | 2336.47 | 0.220994 | 530.305ms | 133023 | 384 | 5.52874e+06 | 54296 | 0.0270197 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 6331.1 | 0.202534 | 201.253ms | 135092 | 384 | 652273 | 20349.3 | 0.534411 | 1(Win) | true |
| std_memcpy | 2405.54 | 0.172111 | 561.043ms | 135195 | 30 | 255289 | 53597.9 | 0.491128 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 11497.9 | 0.226052 | 211.731ms | 261193 | 214 | 513240 | 21664.3 | 0.186363 | 1(Win) | true |
| std_memcpy | 5013.57 | 0.255347 | 488.134ms | 261083 | 214 | 3.44141e+06 | 49662.8 | 0.308632 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 10715.1 | 0.276451 | 228.9ms | 263222 | 214 | 897646 | 23427.6 | 0.9984 | 1(Win) | true |
| std_memcpy | 5062.88 | 0.117963 | 485.515ms | 263172 | 384 | 1.31314e+06 | 49572.7 | 0.033632 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/macOS-GCC/branch-decomp/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | -------- | --------- |
| memcpy_decomp | 11737.9 | 0.205489 | 213.775ms | 265557 | 214 | 420654 | 21575.8 | 0.837088 | 1(Win) | true |
| std_memcpy | 5147.36 | 0.182885 | 483.328ms | 265811 | 48 | 389381 | 49248 | 0.160535 | 2(Loss) | true |
