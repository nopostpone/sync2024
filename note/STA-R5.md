# [『STAOI』G - Round 5](https://www.luogu.com.cn/contest/156888)

*C太难，这里就不看了（）*

参加的第一个比较常规(?)的IOI模拟赛，四道题只做出来送分的第一题和第四题（此题）的一个送分的任务点，喜提117分。但题目都看过一遍，感觉挺有意思的（尤其是T4），遂记录在此文档。

*（希望下次能起码多做一道题= =）*


## [A 5k.sync.closer](https://www.luogu.com.cn/problem/P10397)
没什么好说的，太简单了。

## [B Remove and Decrease Game](https://www.luogu.com.cn/problem/P10398)
涉及博弈论，我完全推不出来，蒙的也全是错的（; w ;）
## [C ReLyna](https://www.luogu.com.cn/problem/P10399)
题看都看不懂，就不写题解了。
## [D 消失的计算机](https://www.luogu.com.cn/problem/P10400)
>*[[题解页面](https://www.luogu.com.cn/problem/solution/P10400)]*
>*[[参考代码](/SPOJ/(luogu)P10400)]*
### 题意：

对于给定的未知正整数 $n$，和 $10^3$ 个变量 $p_1,p_2,\cdots,p_{10^3}$（初始 $p_1=n$，$p_2=p_3=\cdots=p_{10^3}=0$ ）。

我有以下的指令：
- `new x`，令 $n\gets n+1$，$p_x\gets n$。
- `dec x`，令 $p_x\gets p_x-1$。
- `assign x y`，令 $p_x\gets p_y$。
- `iftry x goto l`，如果 $p_x \ge 0$，跳转到第 $l$ 条语句。
- `ifeq x y goto l`，如果 $p_x = p_y$，跳转到第 $l$ 条语句。
- `ifneq x y goto l`，如果 $p_x\neq p_y$，跳转到第 $l$ 条语句。

**对于跳转，只能往前跳不能往后跳**

令程序执行前的 $n$ 值为程序的输入，程序执行后的 $n$ 值为程序的输出，需要分别完成下面 $10$ 个任务：

1. 输入 $n$，输出 $2n$。
1. 输入 $n$，输出 $\binom n2$。
1. 输入 $n$，输出 $600$。
1. 输入 $n$，输出 $n + 1$。
1. 输入 $n$，输出 $n^2 - 1$。
1. 输入 $n$，输出 $n + 2000$。
1. 输入 $n$，输出 $n + \lfloor \log_2 n\rfloor$。
1. 输入 $n$，输出 $n + \left(n \bmod 2\right) + 1$。
1. 输入 $n$，输出 $n+\gcd(n, n - 4) + 1$。
1. 输入 $n$，输出一个满足 $|x-n\ln n|\le 30$ 的正整数 $x$。

**使用的语句不超过 $1000$ 条语句，程序实际语句运行次数不得超过 $10^5$ ，题目保证$5\leq n\leq 100$ 。**

### 思路：

一眼望过去，4肯定是最简单的，仅需要一条new操作就行。

第二眼望过去，1好像也挺简单的，我们已经有一个`p[1]=n`了，如果能在new操作的同时`dec 1`，检测当`p[1]`为非正数的时候结束即可。

接下来好像就没有送的了，让我们重新审视一下题目给的操作指令：
- 对于前三条，我们知道了可以让n自增、把n赋值给某变量、让某变量自减、把一个变量赋值给另一个变量。
- 对于后三条，我们知道了可以做一个形似`do while`的循环结构，用是否为负数、是否相等做循环条件。

能循环，能自增，我们是否能将它们组合一下，实现自增（a*b）的量呢？

下面举出一个例子：

```
assign 2 1
dec 2
assign 3 2 
dec 3
assign 5 1
assign 4 1
new 1
dec 4 
ifneq 4 2 goto 7
dec 5
if neq 5 3 goto 6
```
分析一下上述代码：
1. 先赋值：`p[2]=n-1, p[3]=p[2]-1=n-2, p[4]=p[5]=n`
1. 第一层循环同问题1的解，在让n自增的同时让`p[2]`自减，等`p[2]==p[4]`时跳出循环。
1. 第二层循环是从`assign 4 1`开始的，也就是每次循环都要重新把 $n$ 赋值给 $p_4$ ，然后再走一遍第一层循环。

因此，形似上述代码可以让n增大 $a\cdot b$ ，而 $a$ 和 $b$ 的值可以由我们操控。

掌握这一逻辑之后，就可以完成剩下的任务了。

### code:
$task1: 2n=n+n$
```
3
dec 1
new 2
ifneq 1 3 goto 1
```

$task2: \binom n2 = \sum_{k=1}^nk = n+\sum_{k=1}^{n-2}k$
```
9
dec 1
dec 1
dec 1
assign 2 1
dec 2
new 3
iftry 2 goto 5
dec 1
ifneq 1 4 goto 4
```

$task3: 600=n+(600-n)=n+(24*25-n)$
```
35
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
assign 3 2
dec 3
dec 4
assign 5 6
dec 5
dec 1
ifneq 5 3 goto 29
ifneq 4 2 goto 27
dec 6
new 8
ifneq 1 6 goto 33
```

$task5: n^2-1= (n-1)(n+1)=n+(n+1)(n-2)+1$
```
10
assign 2 1
dec 2
dec 2
new 4
dec 1
assign 3 2
dec 3
new 4
ifneq 3 5 goto 7
iftry 1 goto 5
```

$task6:n+2000=n+2\cdot 10\cdot 10\cdot 10$
```
24
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 2
dec 3
dec 3
dec 4
assign 5 8
dec 5
assign 6 8
dec 6
assign 7 8
dec 7
new 9
ifneq 7 2 goto 19
ifneq 6 2 goto 17
ifneq 5 2 goto 15
ifneq 3 4 goto 13
```

$task7:$ 将 p1 一直减去2的幂次，若为非负则倍增，次数加一。
```
13
assign 2 1
dec 3
dec 3
dec 2
dec 2
new 7
assign 4 3
assign 5 6
dec 5
dec 3
dec 2
ifneq 5 4 goto 9
iftry 2 goto 6
```

$task8:$
```
6
dec 1
dec 1
iftry 1 goto 1
dec 2
new 3
ifeq 1 2 goto 4
```

$task9:$
```
18
dec 1
dec 1
dec 1
dec 1
assign 2 1
dec 2
iftry 2 goto 1
dec 3
dec 3
assign 4 3
dec 4
dec 4
new 5
new 5
dec 1
dec 1
ifeq 1 4 goto 14
ifeq 1 3 goto 13
```

$task10:$
```
11
assign 2 1
dec 1
new 4
new 4
new 4
ifneq 1 3 goto 2
dec 2
dec 2
dec 2
new 4
iftry 2 goto 7
```