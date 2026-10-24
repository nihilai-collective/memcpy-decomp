# memcpy Decomposition
Performance profiling of functions (Compiled and run on Windows 10.0.26100 using the MSVC 19.51.36260.0 compiler).  

Latest Results: (Oct 24, 2026)

> Adaptive sampling on (AMD EPYC 7763 64-Core Processor-AVX2): iterations begin at 60 and double each epoch (e.g. 60 ? 120 ? 240 ? ...) up to a per-test-size maximum (scaled so every size gets the same iterations*count memory/verification budget - smaller copy counts get proportionally more iterations to average out timing noise). Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Sampling does not stop early: epochs continue until 10 seconds have elapsed or the iteration cap is reached. The first epoch is kept only as an initial fallback; every later epoch is scored by its RSE plus its epoch-over-epoch mean shift (%), and the lowest-scoring epoch is retained as the canonical result, whether or not it met the convergence thresholds. A result counts as converged only if that retained epoch has RSE <= 10% AND mean shift <= 5%; non-converged results are still included in the rankings and in win/tie/loss tallying, so a result that did not meet these thresholds should be read with its reduced statistical confidence in mind. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
 This is the commit of BenchmarkSuite that was used to generate these results: [ab75024](https://github.com/nihilai-collective/benchmarksuite/commit/ab75024).
 
----
### copy_count[4096]-length[1-15] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-15%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1390.88 | 0.194142 | 223.221ms | 32752 | 30 | 57023 | 22456.7 | 0.236932 | 1.67551 | 1(Win) | true |
| std_memcpy | 729.922 | 0.617625 | 419.651ms | 32781 | 192 | 1.34351e+07 | 42829.7 | 0.0717989 | 3.19197 | 2(Loss) | true |

----
### copy_count[4096]-length[1-16] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-16%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1335.18 | 0.175018 | 247.05ms | 34763 | 30 | 56655.2 | 24830 | 0.347826 | 1.74432 | 1(Win) | true |
| std_memcpy | 774.295 | 0.603587 | 419.553ms | 34759 | 192 | 1.28204e+07 | 42811.5 | 0.0656519 | 3.00949 | 2(Loss) | true |

----
### copy_count[4096]-length[1-17] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-17%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 1377.88 | 0.171481 | 252.752ms | 36798 | 48 | 91555.9 | 25468.8 | 0.191778 | 1.68963 | 1(Win) | true |
| std_memcpy | 863.065 | 0.636671 | 398.945ms | 36802 | 192 | 1.28702e+07 | 40665.6 | 0.0128061 | 2.69978 | 2(Loss) | true |

----
### copy_count[4096]-length[1-31] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-31%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2595.22 | 0.500347 | 236.685ms | 65575 | 384 | 5.58208e+06 | 24096.9 | 0.0605563 | 0.897339 | 1(Win) | true |
| std_memcpy | 1617.37 | 0.627027 | 378.629ms | 65553 | 214 | 1.25704e+07 | 38652.8 | 0.146815 | 1.44057 | 2(Loss) | true |

----
### copy_count[4096]-length[1-32] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-32%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2387.53 | 0.399744 | 265.117ms | 67738 | 384 | 4.49217e+06 | 27057 | 0.0125137 | 0.975547 | 1(Win) | true |
| std_memcpy | 1719.8 | 0.174492 | 372.525ms | 67715 | 30 | 128793 | 37550 | 0.142235 | 1.35473 | 2(Loss) | true |

----
### copy_count[4096]-length[1-33] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-33%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 2333.22 | 0.59415 | 279.361ms | 69826 | 384 | 1.10421e+07 | 28540.6 | 0.116656 | 0.998238 | 1(Win) | true |
| std_memcpy | 1715.29 | 0.702035 | 380.395ms | 69824 | 214 | 1.58952e+07 | 38821 | 0.00385576 | 1.35831 | 2(Loss) | true |

----
### copy_count[4096]-length[1-63] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-63%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 4793.33 | 0.683602 | 255.861ms | 131679 | 384 | 1.23168e+07 | 26198.7 | 0.148327 | 0.485896 | 1(Win) | true |
| std_memcpy | 3478.45 | 0.637797 | 352.141ms | 131759 | 384 | 2.03839e+07 | 36124 | 0.277593 | 0.669695 | 2(Loss) | true |

----
### copy_count[4096]-length[1-64] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-64%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 4372.19 | 0.54636 | 284.73ms | 132981 | 384 | 9.64435e+06 | 29006.2 | 0.159553 | 0.532693 | 1(Win) | true |
| std_memcpy | 3529.45 | 0.765641 | 355.362ms | 133034 | 192 | 1.45432e+07 | 35946.4 | 0.226964 | 0.660207 | 2(Loss) | true |

----
### copy_count[4096]-length[1-65] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-65%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 4388.41 | 0.500964 | 287.674ms | 135073 | 192 | 4.15182e+06 | 29353.6 | 0.594398 | 0.530793 | 1(Win) | true |
| std_memcpy | 3509.65 | 0.530655 | 361.478ms | 135103 | 96 | 3.64334e+06 | 36711.5 | 0.150611 | 0.66384 | 2(Loss) | true |

----
### copy_count[4096]-length[1-127] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-127%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 9080.31 | 0.950561 | 267.677ms | 261193 | 214 | 1.45511e+07 | 27432.2 | 0.254885 | 0.256464 | 1(Win) | true |
| std_memcpy | 5328.44 | 0.552403 | 457.755ms | 261054 | 214 | 1.42556e+07 | 46722.9 | 0.128071 | 0.43735 | 2(Loss) | true |

----
### copy_count[4096]-length[1-128] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-128%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 8734.08 | 0.876938 | 280.393ms | 263170 | 214 | 1.35891e+07 | 28735.5 | 0.280248 | 0.266641 | 1(Win) | true |
| std_memcpy | 5320.95 | 0.481991 | 466.977ms | 263145 | 384 | 1.98437e+07 | 47163.5 | 0.135646 | 0.437953 | 2(Loss) | true |

----
### copy_count[4096]-length[1-129] Results 

<p align="left"><a href="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png" target="_blank"><img src="./graphs/Windows-MSVC/branch-up-to/copy_count%5b4096%5d-length%5b1-129%5d-Results.png?raw=true" 
alt="" width="400"/></a></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Mean Convergence (%) | Cycles/Byte | Position | Converged |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ---------------- | ----------- | -------- | --------- |
| memcpy_decomp_up_to | 8920.58 | 0.325464 | 280.703ms | 265807 | 30 | 256609 | 28416.7 | 0.0937537 | 0.261069 | 1(Win) | true |
| std_memcpy | 5492.39 | 0.448913 | 451.956ms | 265668 | 384 | 1.64669e+07 | 46129.4 | 0.262945 | 0.424258 | 2(Loss) | true |
