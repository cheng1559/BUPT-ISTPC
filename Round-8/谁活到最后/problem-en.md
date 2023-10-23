# Who is the Last

### Description

Assume that there are $x$ people standing in a circle, numbered from $1$ to $n$ in clockwise order. The first person starts counting from $1$, and the person who counts to $n$ is eliminated. The next person starts counting from $1$ again, and the person who counts to $n$ is eliminated. This process continues until there is only one person left. Who is the last person?

For example, when $x = 10$, $n = 2$, the process is as follows:

- Initially, the circle is $[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]$.
- The first person starts counting from $1$, and the second person  is eliminated. The circle becomes $[1, 3, 4, 5, 6, 7, 8, 9, 10]$.
- The third person starts counting from $1$, and the fourth person is eliminated. The circle becomes $[1, 3, 5, 6, 7, 8, 9, 10]$.
- The fifth person starts counting from $1$, and the sixth person is eliminated. The circle becomes $[1, 3, 5, 7, 8, 9, 10]$.
- The seventh person starts counting from $1$, and the eighth person is eliminated. The circle becomes $[1, 3, 5, 7, 9, 10]$.
- The ninth person starts counting from $1$, and the tenth person is eliminated. The circle becomes $[1, 3, 5, 7, 9]$.
- The first person starts counting from $1$, and the third person is eliminated. The circle becomes $[1, 5, 7, 9]$.
- The fifth person starts counting from $1$, and the seventh person is eliminated. The circle becomes $[1, 5, 9]$.
- The ninth person starts counting from $1$, and the first person is eliminated. The circle becomes $[5, 9]$.
- The fifth person starts counting from $1$, and the ninth person is eliminated. The circle becomes $[5]$.

Therefore, the last person is the fifth person.

Given the number of people $x$ and the number of people counted $n$, please give the number of the last person.

### Input Format

The first line contains two integers $x$ and $n$, respectively, indicating the number of people and the number of people counted each time. ($1 \le x \le 10^{15}$, $1 \le n \le 10$)

### Output Format

One line, one integer, the number of the last person.

### Sample #1

#### Input Sample #1

```
10 2
```

#### Output Sample #1

```
5
```

### Sample #2

#### Input Sample #2

```
10 3
```

#### Output Sample #2

```
4
```

### Hint

Example #1 is the same as the example in the description.

In Example #2, the people is eliminated in the order $3,6,9,2,7,1,8,5,10$, so the last person is the fourth person.

Hint:
1. Find a pattern and solve the recurrence relation.
2. The $n$ in the description is far less than $x$, which indicate a way to optimize the algorithm.