# Multiple Choice

## 题目背景

日常签到送分环节。

## 题面翻译

1. 栈和队列的元素进出顺序分别为（ ）。

A. 先进先出、先进后出

B. 先进后出、先进先出

C. 先进先出、先进先出

D. 先进后出、先进后出

2. 若要删除单链表的第$k$个节点（从$1$开始计数），则需获取指向第（ ）个结点的指针。(假设你不需要释放删除节点的内存)

A. $1$

B. $k-1$

C. $k$

D. $k+1$

***阅读以下代码，并回答问题3、4。***
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int stack[n], idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx > 0 && stack[idx - 1] > arr[i]) {
            idx--;
        }
        stack[idx] = arr[i];
        idx++;
    }
    while (idx > 0) {
        printf("%d ", stack[idx - 1]);
        idx--;
    }
    return 0;
}
```
3. 这段代码的时间复杂度为（ ）。

A. $O(n^2)$

B. $O(n)$

C. $O(\lg n)$

D. $O(n\lg n)$

4. 若进行以下输入，则输出结果为（ ）。
```
10
3 2 1 4 8 7 6 2 9 5
```
A. `5 2 1`

B. `1 2 5`

C. `3 4 8 9`

D. `9 8 4 3`

5. 以下四个字符串中，字典序最大的是（ ）。

A. $apple$

B. $appleeeeeeeee$

C. $applezk$

D. $applezfb$

**字典序的定义较为形式化地给出：**

字符串 $a$ 在字典序上小于字符串 $b$ ，当且仅当 $a$ 是 $b$ 的前缀（且 $a\neq b$），或者存在一个索引 $i$（$1 ≤ i ≤ \min(|a|, |b|)$），满足 $a_i < b_i$，并且对于任何索引 $j$（$1 ≤ j < i$），$a_j = b_j$。

## 题目描述

1. The element input and output order of stack and queue are respectively ( ).

A. First-In First-Out, First-In Last-Out

B. First-In Last-Out, First-In First-Out

C. First-In First-Out, First-In First-Out

D. First-In Last-Out, First-In Last-Out

2. If you want to delete the $k$-th node of a singly linked list (counting from $1$), you need to get a pointer to the ( )-th node. (Assume that you don't need to `free` the memory of the deleted node)

A. $1$

B. $k-1$

C. $k$

D. $k+1$

***Read the following code and answer question 3 and 4.***

```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int stack[n], idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx > 0 && stack[idx - 1] > arr[i]) {
            idx--;
        }
        stack[idx] = arr[i];
        idx++;
    }
    while (idx > 0) {
        printf("%d ", stack[idx - 1]);
        idx--;
    }
    return 0;
}
```

3. The time complexity of this code is ( ).

A. $O(n^2)$

B. $O(n)$

C. $O(\lg n)$

D. $O(n\lg n)$

4. If the following input is entered, the output is ( ).

```
10
3 2 1 4 8 7 6 2 9 5
```

A. `5 2 1`

B. `1 2 5`

C. `3 4 8 9`

D. `9 8 4 3`

5. Among the following four strings, the one with the largest lexicographic order is ( ).

A. $apple$

B. $appleeeeeeeee$

C. $applezk$

D. $applezfb$

**Formally, lexicographic order is defined as:**

String $a$ is less than string $b$ in lexicographic order if and only if $a$ is a prefix of $b$ (and $a\neq b$), or there exists an index $i$ ($1 ≤ i ≤ \min(|a|, |b|)$) such that $a_i < b_i$, and for any index $j$ ($1 ≤ j < i$), $a_j = b_j$.

## 输入格式

None.

## 输出格式

Output 5 letters in any format, each letter represents the answer to the corresponding question.

The checker is case-insensitive and it will ignore all unrelated characters, such as spaces, line-breaks, numbers, punctuations and emojis.

## 样例 #1

### 样例输入 #1

```

```

### 样例输出 #1

```
AAAAA
```

## 提示

**The sample output is only for the purpose of explanation. It is not the correct answer.**