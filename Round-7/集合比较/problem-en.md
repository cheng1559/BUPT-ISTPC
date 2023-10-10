# Comparing Sets

## Description

In this problem, you are given 2 sets $X$ and $Y$. Please compare them in the following way:

- If $X$ is a proper subset of $Y$, output `<`.
- If $Y$ is a proper subset of $X$, output `>`.
- If $X$ equals $Y$, output `=`.
- Otherwise, output `.`.

## Input Format

The first line starts with an integer $n$ ($0 \leq n \leq 10^5$), the number of elements in set $X$, followed by $n$ strictly increasing integers $x_i$ ($0 \leq x_i \leq 10^9$), the elements in set $X$. ($\forall i \in [1, n - 1], x_i < x_{i+1}$)

The second line starts with an integer $m$ ($0 \leq m \leq 10^5$), the number of elements in set $Y$, followed by $m$ strictly increasing integers $y_i$ ($0 \leq y_i \leq 10^9$), the elements in set $Y$. ($\forall i \in [1, m - 1], y_i < y_{i+1}$)

## Output Format

One line, one of `<`, `>`, `=`, `.` as described in the problem statement.

## Sample #1
### Sample Input #1

```
0
0
```

### Sample Output #1

```
=
```

## Sample #2
### Sample Input #2

```
2 1 2
1 1
```

### Sample Output #2

```
>
```

## Note

In sample #1,
$$
\varnothing = \varnothing
$$

In sample #2,
$$
\{1, 2\} \supset \{1\}
$$

### Subtasks

Easy (57 points): $n, m \leq 5$. **You must pass this subtask to get any score.**

Hard (43 points): $n, m \leq 10^5$. Partial score is calculated by the number of passed test cases.

### Language Knowledge

Some contestants may be unfamiliar with data structures, so we provide some useful functions or classes in the standard library of C/C++/Java/Python. If you have done our data structure homework, you may not need them.

- [C bsearch](https://www.runoob.com/cprogramming/c-function-bsearch.html)

- [C++ set](https://blog.csdn.net/qq_50285142/article/details/122304728)

- [Java HashSet](https://www.runoob.com/java/java-hashset.html)

- [Python set](https://www.runoob.com/python/python-func-set.html)