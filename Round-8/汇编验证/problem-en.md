# Assembly Verification

## Problem Background

Suppose there is a stack virtual machine, and we need to verify whether a function on this virtual machine is legal.

To simplify the problem, this function only uses the `call` instruction.

Each function has a natural number of parameters and either has or does not have a return value. The parameters and return value have a determined type.

Function $f_0(type_1\ x_1, type_2\ x_2, ..., type_n\ x_n)$ starts by opening a stack, which stores each parameter $S_0=[x_1, x_2, ..., x_n]$.

After this, every time a `call f_i` instruction is encountered:
- If the current stack is $S_{prev}=[x_1, x_2, ..., x_n]$, and $f_i$ has $m_i$ parameters, pop the top $m_i$ parameters from the stack, and use them **in the order they were pushed** as the parameters for the call to $f_i$, i.e. call $f_i(x_{n - m + 1}, x_{n - m + 2}, ... , x_n)$. **If there are not $m_i$ parameters on the stack, or the parameter types do not match, then this assembly is illegal.**
  - If $f_i$ has a return value, push its return value onto the stack, and the stack becomes $S_{next}=[x_1, x_2, ..., x_{n - m}, f_i(x_{n - m + 1}, x_{n - m + 2}, ... , x_n)]$.
  - If $f_i$ does not have a return value, do not push anything, and the stack becomes $S_{next}=[x_1, x_2, ..., x_{n - m}]$.

**When the function ends, if there is a return value, there must be exactly one element on the stack, and it must be of the same type as the declared return value. If there is no return value, the stack must be empty, otherwise this assembly is also illegal.**

## Problem Description

Now, given the assembly of $f_0$, which is only composed of `call` instructions, and the parameter type list and return value type of the functions $f_1, f_2, ..., f_n$ that it may call.

For convenience, all types are represented by positive integers.

## Input Format

The first line contains an integer $n$, which represents the number of functions that $f_0$ may call. ($1 \le n \le 1000$)

The next $n$ lines each start with two integers $r_i$ and $c_i$, representing the return value type and the number of parameters of $f_i$, followed by $c_i$ integers $p_{i, j}$, representing the type of each parameter. If there is no return value, then $r_i = 0$. ($0 \le r_i \le 200$, $0 \le c_i \le 32$, $1 \le p_{i, j} \le 200$)

The next line starts with three integers $s$, $r$, and $c$, representing that the function $f_0$ to be verified has $s$ lines of assembly, a return value type of $r$, and $c$ parameters, followed by $c$ integers $p_j$, representing the type of each parameter. If there is no return value, then $r_i = 0$. ($1 \le s \le 10^4$, $0 \le r \le 200$, $0 \le c \le 32$, $1 \le p_j \le 200$)

The next $s$ lines each contain an integer $j$, representing a $call\ f_j$ instruction in the assembly of $f_0$. ($1 \le j \le n$)

## Output Format

If $f_0$ is legal, output `YES`, otherwise output `NO`.

## Example #1

### Input Example #1

```
4
0 1 2
5 3 2 3 4
5 1 5
0 1 5
4 5 4 2 3 4 5
4
2
3
3
```

### Output Example #1

```
YES
```

## Example #2

### Input Example #2

```
4
0 1 2
5 3 2 3 4
5 1 5
0 1 5
4 0 4 2 3 4 5
4
2
3
3
```

### Output Example #2

```
NO
```

## Hint

In Example #1, the declared functions are:
```c
void f1(t2 a);
t5 f2(t2 a, t3 b, t4 c);
t5 f3(t5 a);
void f4(t5 a);
```
The function to be verified is:
```c
t5 f0(t2 a, t3 b, t4 c, t5 d) {
	// Stack/Assembly
	// S = [a, b, c, d]
	// call f4
	f4(d);
	// S = [a, b, c]
	// call f2
	t5 e = f2(a, b, c);
	// S = [e]
	// call f3
	t5 f = f3(e);
	// S = [f]
	// call f3
	t5 g = f3(f)
	// S = [g]
	// At the end of the function, return the only element on the stack
	return g;
}
```
So it is valid.

In Example #2, only the return value of $f_0$ is declared as `void`, and everything else is the same as Example #1. Obviously, this is not legal.