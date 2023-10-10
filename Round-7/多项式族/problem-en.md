# Polynomial Family

## Background

Noticing that we always get an arbitrary constant $C$ when we perform indefinite integration. For example, $\int x^2 \mathrm{d}x = \frac{1}{3}x^3 + C$. In this case, the right side is called a original function family.

To make it easier to study, Paimon decides to propose a narrower definition, polynomial family, which is in the form of (1)

$$
a_n x^n + a_{n-1} x^{n-1} + ... + a_2x^2 + a_1x + C
$$

Paimon calls two polynomials $f$ and $g$ **in the same family** if and only if there exists a constant $C \in \mathbb R$ such that for any $x \in \mathbb R$, we have

$$
f(x) = g(x) + C
$$

(1): This concept is made up by the problem setter, you probably can't find it anywhere else.

## Description

Now, there are two polynomials $f$ and $g$ with order at most $n$.

Paimon knows the function values of $f$ at $n + 1$ points, and the function values of $g$ at $n + 1$ points.

Now, she wonders whether $f$ and $g$ are in the same family. If so, she wants to know the constant $C = f(x) - g(x)$.

## Input Format

The first line contains an integer $n$, indicating that the order of $f$ and $g$ is at most $n$. ($0 \leq n \leq 8$)

The next $n + 1$ lines, each line contains two integers $x_{f,i}$ and $f(x_{f,i})$, indicating the $i$-th point on the function $f(x)$, and there will be no duplicate points. ($-100 \leq x_{f,i} \leq 100$, $-10^9 \leq f(x_{f,i}) \leq 10^9$)

The next $n + 1$ lines, each line contains two integers $x_{g,i}$ and $g(x_{g,i})$, indicating the $i$-th point on the function $g(x)$, and there will be no duplicate points. ($-100 \leq x_{g,i} \leq 100$, $-10^9 \leq g(x_{g,i}) \leq 10^9$)

## Output Format

The first line contains `YES` or `NO` (case insensitive), answering whether $f$ and $g$ are in the same family.

If the first line answers `YES`, the second line contains a floating point number $C$ (no requirement on the number of digits after the decimal point), indicating the constant difference. If the first line answers `NO`, there will be no second line.

Your answer will be accepted if and only if the relative or absolute error between your answer and the jury's answer does not exceed $10^{-6}$.

## Sample #1

### Sample Input #1

```
2
0 0
1 1
2 4
3 10
4 17
5 26
```

### Sample Output #1

```
YES
-1.000000000
```

## Sample #2

### Sample Input #2

```
1
0 1
1 2
0 2
3 2
```

### Sample Output #2

```
NO
```

## Note

In sample #1, $f(x) = x^2$, $g(x) = x^2 + 1$, so are in the same family and the constant difference is $C = f(x) - g(x) = -1$.

In sample #2, $f(x) = x + 1$, $g(x) = 2$, so they are not in the same family.

### Subtasks

Easy (57 points): $n \leq 1$, that is $f$ and $g$ are both linear functions. **You must pass this subtask to get any score.**

Hard (43 points): $n \leq 8$. Partial score is calculated by the number of passed test cases.

**In particular, the sample data of this problem is not Test #1 of Subtask #0, because it does not meet the data range of the easy subtask.**