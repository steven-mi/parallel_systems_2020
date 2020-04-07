# Simple C Project - Integral
This is a simple C project for calculating the integral of any function. The main app calculates the discrete integral of `sqrt(1 - x^2)` and multiplies it with 2, resulting in the number PI as a return. The calculated estimation of PI will then be printed to the terminal. As an input parameter, the amount of steps used, is defined. Given that we are using a estimation to calculate the integral, the higher the input value, the more accurate is our PI estimation.

```bash
make 
./integrale 10000
```
