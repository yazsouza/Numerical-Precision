# Numerical-Precision
This project aimed to simulate a parallel addition algorithm to evaluate the sum of the alternating harmonic series
using 4 parallel processors, with the goal of achieving the highest precision possible. I was able to achieve a precision of 1.9*10^-9 by implementing a Kahan summation algorithm. This was accomplished by keeping a compensation variable to accumulate the value of small errors in the summation, in effect extending the precision of the sum by the precision of the compensation variable. 
