# 埃及分数

## 题目背景

埃及分数是将一个分数$p \over q$表示为一个有限长度的严格递增正整数序列$n_1, n_2, ... , n_k$的倒数的和。

摘自课本：

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

## 题目描述

现在，给出一个真分数的埃及形式$n_1, n_2, ... , n_k$.

请给出另一组正整数$m_1, m_2, ... , m_l$，使得这两组正整数表达同一个真分数。

请注意，本题仅讨论真分数，即大于0小于1的分数。

## 输入格式

第一行一个正整数$k$，输入的埃及形式中的整数的个数。($1 \leq k \leq 50$)。

第二行$k$个正整数$n_i$，输入的埃及形式中的正整数。($2 \leq n_i \leq 10^4$)。($\forall i \in [1, k - 1], n_i < n_{i+1}$)

## 输出格式

第一行一个正整数$l$，输出的埃及形式中的整数的个数。($1 \leq l \leq 100$)。

第二行$l$个正整数$m_i$，输出的埃及形式中的正整数。($2 \leq m_i \leq 10^9$)。($\forall i \in [1, l - 1], m_i < m_{i+1}$)

输出不得与输入完全相同，其中完全相同是指$l = k$且$\forall i \in [1, l], m_i = n_i$。

## 样例 #1

### 样例输入 #1

```
3
2 4 30
```

### 样例输出 #1

```
3
3 4 5
```

## 提示

样例#1：
$$
{1 \over 2} + {1 \over 4} + {1 \over 30} = {47 \over 60} = {1 \over 3} + {1 \over 4} + {1 \over 5}
$$

### 子任务
简单（57分）：$k \leq 12$，**你必须通过该子任务才能获得分数。**

困难（43分）：$k \leq 50$，按测试点计算部分分。