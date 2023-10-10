# 集合比较

## 题目描述

给出两个集合$X$和$Y$，比较这两个集合。

- 如果$X$是$Y$的真子集，输出`<`。
- 如果$Y$是$X$的真子集，输出`>`。
- 如果$X$等于$Y$，输出`=`。
- 否则，输出`.`。

## 输入格式

第一行开头有一个整数$n$($0 \leq n \leq 10^5$)，接下来有$n$个递增的整数$x_i$($0 \leq x_i \leq 10^9$)，表示集合$X$中的元素。($\forall i \in [1, n - 1], x_i < x_{i+1}$)

第二行开头有一个整数$m$($0 \leq m \leq 10^5$)，接下来有$m$个递增的整数$y_i$($0 \leq y_i \leq 10^9$)，表示集合$Y$中的元素。($\forall i \in [1, m - 1], y_i < y_{i+1}$)

## 输出格式

一行，`<`、`>`、`=`、`.`之一，见题干。

## 样例 #1

### 样例输入 #1

```
0
0
```

### 样例输出 #1

```
=
```

## 样例 #2

### 样例输入 #2

```
2 1 2
1 1
```

### 样例输出 #2

```
>
```

## 提示

### 子任务
简单（57分）：$n, m \leq 5$，**你必须通过该子任务才能获得分数。**

困难（43分）：$n, m \leq 10^5$，按测试点计算部分分。

### 语言知识

可能有用的语言知识（有些人可能用到）：

- [C bsearch](https://www.runoob.com/cprogramming/c-function-bsearch.html)

- [C++ set](https://blog.csdn.net/qq_50285142/article/details/122304728)

- [Java HashSet](https://www.runoob.com/java/java-hashset.html)

- [Python set](https://www.runoob.com/python/python-func-set.html)