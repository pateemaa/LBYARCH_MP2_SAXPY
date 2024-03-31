## LABYARCH Machine Project 2: SAXPY (A*X + Y) function implementation
### Submitted by: DY, Fatima Kriselle and GUTIERREZ, Mark Daniel
### Comparative Analysis

|  n  |  C - Debug  |  C - Release  | Assembly - Debug  |  Assembly - Release  |
| :---: | :---: | :---: | :---: | :---: |
| 2<sup>20</sup> |  0.004900  |  0.002733  |  0.002967  |  0.001533  |
| 2<sup>24</sup> |  0.066233  |  0.043367  |  0.051033  |  0.030033  |
| 2<sup>27</sup> |  0.496667  |  0.376533  |  0.310067  |  0.255167  |

**Table 1. Summary of execution time in CPU clock time**

The assembly version constantly outperformed the C version across all input sizes (n) and modes. As the input size increases, the performance difference between C and Assembly becomes prominent. As shown in table 1, at n = 2<sup>20</sup>, assembly is approximately 0.001933 seconds faster than C in debug mode and approximately 0.001197 seconds faster in release mode. Similarly, at n = 2<sup>24</sup>, assembly is approximately 0.0152 seconds faster than C in debug mode and approximately 0.013334 seconds faster in release mode. Lastly, at n = 2<sup>27</sup>, assembly is approximately 0.1866 seconds faster than C in debug mode and approximately 0.121366 seconds faster in release mode.

### Screenshots of output
