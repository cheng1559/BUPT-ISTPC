# 谁活到最后

## 题目背景

假设有$x$个人围成一圈，编号$1$到$x$，每$n$个人杀死第$n$个人（**注意不是每隔$n$个人**），请问谁活到最后？

举例，当$x = 10$，$n = 2$时，步骤如下：

- 初始化状态$[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]$。
- 从$1$号开始往后数$2$位，杀死$2$号$[1, 3, 4, 5, 6, 7, 8, 9, 10]$。
- 从$3$号开始往后数$2$位，杀死$4$号$[1, 3, 5, 6, 7, 8, 9, 10]$。
- 从$5$号开始往后数$2$位，杀死$6$号$[1, 3, 5, 7, 8, 9, 10]$。
- 从$7$号开始往后数$2$位，杀死$8$号$[1, 3, 5, 7, 9, 10]$。
- 从$9$号开始往后数$2$位，杀死$10$号$[1, 3, 5, 7, 9]$。
- 从$1$号开始往后数$2$位，杀死$3$号$[1, 5, 7, 9]$。
- 从$5$号开始往后数$2$位，杀死$7$号$[1, 5, 9]$。
- 从$9$号开始往后数$2$位，杀死$1$号$[5, 9]$
- 从$5$号开始往后数$2$位，杀死$9$号$[5]$

因此活下来的人是$5$号。

## 题目描述

给出人数$x$，每次杀人向后数的个数$n$，请给出活到最后的人的编号。

## 输入格式

第一行两个整数，$x$和$n$，分别表示人数、每次杀人向后数的个数$n$。（$1 \le x \le 10^{15}$，$1 \le n \le 10$）

## 输出格式

一行，一个整数，活下来的人的编号。

## 样例 #1

### 样例输入 #1

```
10 2
```

### 样例输出 #1

```
5
```

## 样例 #2

### 样例输入 #2

```
10 3
```

### 样例输出 #2

```
4
```

## 提示

样例#1即为题干中所给例子。

样例#2中，按顺序杀死$3,6,9,2,7,1,8,5,10$，剩余$4$号。


提示：
1. 找规律，解递归。
2. 数据范围中$n$特别小。