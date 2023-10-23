# Playing Cards

## Problem Description

Alice has designed a card game with a total of 6 cards labeled $0, 1, 2, 3, 4, 5$.

In each round, Alice plays a card. For the first $q$ rounds, the damage caused is the product of the number of each card played in this round and all previous rounds plus one. After $q$ rounds, the damage caused is the product of the number of each card played in the last $q$ rounds plus one.

Now, given the cards played by Alice in each round $x_i$, output the damage caused in each round $d_i$.

The cards played $x_i$ will be given in a rather strange way, see the input format.

## Input Format

The first line contains two integers $n$ and $q$, respectively, indicating the number of rounds played. For the first $q$ rounds, the damage caused is the product of the number of each card played in this round and all previous rounds plus one. After $q$ rounds, the damage caused is the product of the number of each card played in the most recent $q$ rounds plus one. ($1 \le n \le 10^5$, $1 \le q \le 10^4$)

The next $n$ lines each contain an integer $z_i$. Let $d_0 = 0$, and Alice's card played in round $i$ is $x_i = (d_{i - 1} + z_i) \mod 6$, where $\mod 6$ means taking the remainder when divided by 6. ($0 \le z_i < 6$)

## Output Format

$n$ lines, each containing an integer $d_i$, the damage caused in round $i$.

## Example #1

### Input Example #1

```
3 2
1
2
4
```

### Output Example #1

```
2
4
4
```

## Hint

In Example #1,

1. Play a card $x_1 = (0 + 1) \mod 6 = 1$. There is one $1$ card played, so the damage is $1 + 1 = 2$.
2. Play a card $x_2 = (2 + 2) \mod 6 = 4$. There is one $1$ card and one $4$ card played, so the damage is $(1 + 1)(1 + 1) = 4$.
3. Play a card $x_3 = (4 + 4) \mod 6 = 2$. There is one $1$ card and one $2$ card played, so the damage is $(1 + 1)(1 + 1) = 4$.