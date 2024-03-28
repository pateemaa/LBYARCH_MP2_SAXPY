## LABYARCH Machine Project 2: SAXPY (A*X + Y) function implementation
### Submitted by: DY, Fatima Kriselle and GUTIERREZ, Mark Daniel
### Comparative Analysis

|  n  |  C - Debug  |  C - Release  | Assembly - Debug  |  Assembly - Release  |
| :---: | :---: | :---: | :---: | :---: |
| 2<sup>20</sup> |  0.003067  |  0.000000  |  0.001433  |  0.000000  |
| 2<sup>24</sup> |  0.049767  |  0.000000  |  0.034767  |  0.000000  |
| 2<sup>27</sup> |  0.358133  |  0.000000  |  0.250567  |  0.000000  |

**Table 1. Summary of execution time in CPU clock time**

The assembly version constantly outperformed the C version across all input sizes (n) and modes. As the input size increases, the performance difference between C and Assembly becomes prominent. As shown in table 1, at n = 2<sup>20</sup>, assembly is approximately 0.001634 seconds faster than C in debug mode. Similarly, at n = 2<sup>24</sup>, assembly is approximately 0.015 seconds faster than C in debug mode. Lastly, at n = 2<sup>27</sup>, assembly is approximately 0.107566 seconds faster than C in debug mode.
