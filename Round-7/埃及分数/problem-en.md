# Egyptian Fraction

The Egyption fraction of a fraction $p \over q$ is a finite strictly increasing sequence of positive integers $n_1, n_2, ... , n_k$ whose reciprocal sum is equal to $p \over q$.

From the textbook:

The Egyptians of antiquity expressed a fraction as a sum of fractions whose numerators were 1. For example, 5/6 might be expressed as
$$
{5 \over 6} = {1 \over 2} + {1 \over 3}
$$
We say that a fraction $p/q$, where $p$ and $q$ are positive integers, is
in Egyptian form if
$$
{p \over q} = {1 \over n_1} + {1 \over n_2} + ... + {1 \over n_k}
$$
where $n_1, n_2, ... , n_k$ are positive integers satisfying $n_1 < n_2 < ... < n_k$.

## Description

Now, given an Egyption fraction $n_1, n_2, ... , n_k$.

Please give another sequence of positive integers $m_1, m_2, ... , m_l$ such that these two sequences represent the same proper fraction.

Please note that in this problem we only discuss proper fractions, i.e. fractions greater than 0 and less than 1.

## Input Format

The first line contains an integer $k$, the number of integers in the Egyption fraction. ($1 \leq k \leq 50$).

The second line contains $k$ positive integers $n_i$, the positive integers in the Egyption fraction. ($2 \leq n_i \leq 10^4$). ($\forall i \in [1, k - 1], n_i < n_{i+1}$)

## Output Format

The first line contains an integer $l$, the number of integers in the Egyption fraction. ($1 \leq l \leq 100$).

The second line contains $l$ positive integers $m_i$, the positive integers in the Egyption fraction. ($2 \leq m_i \leq 10^9$). ($\forall i \in [1, l - 1], m_i < m_{i+1}$)

The output must not be exactly the same as the input, where exactly the same means $l = k$ and $\forall i \in [1, l], m_i = n_i$.

## Sample #1
### Sample Input #1

```
3
2 4 30
```

### Sample Output #1

```
3
3 4 5
```

## Note

In sample #1,
$$
{1 \over 2} + {1 \over 4} + {1 \over 30} = {47 \over 60} = {1 \over 3} + {1 \over 4} + {1 \over 5}
$$

## Subtasks

Easy (57 points): $k \leq 12$. **You must pass this subtask to get any score.**

Hard (43 points): $k \leq 50$. Partial score is calculated by the number of passed test cases.