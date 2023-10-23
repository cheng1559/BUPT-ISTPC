# Fourier-Legendre Series Expansion

## Problem Description

Given a function $y = \cos(ax + b), x \in [-1, 1]$, please perform a Fourier-Legendre series expansion on it and find the coefficient of the $P_i$ term.

## Input Format

One line containing three integers $a$, $b$, and $i$, respectively, representing the two parameters in the function and the required term. ($1 \le a \le 100$, $1 \le b \le 100$, $0 \le i \le 30$)

## Output Format

A real number representing the coefficient of $P_i$.

Your answer will be accepted if and only if the relative or absolute error of your answer does not exceed $10^{-6}$.

## Example #1

### Input Example #1

```
1 0 1
```

### Output Example #1

```
0.0000000000
```

## Example #2

### Input Example #2

```
3 4 5
```

### Output Example #2

```
0.1365061995
```

## Hint

In Example #1, it is required to approximate $\cos(x)$ with Legendre polynomials and find the coefficient of the first-order term. Since $\cos(x)$ is an even function, there are obviously no odd-order terms, so the answer is $0$.