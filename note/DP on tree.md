树形DP
===

题单来自：https://www.luogu.com.cn/training/11363#problems

[toc]

## 没有上司的舞会

某大学有 $n$ 个职员，每个员工有快乐值 $r_i$。

他们的从属关系可以构成一棵树，树的结构为：**上司 $\rightarrow$ 下属**。

有一个宴会，如果邀请一个人的（直接）上司，这个人就不会来。问最大的总快乐值。

<details>

设 $f_{i, j}$ 为以 $i$ 为根的子树，且 $i$ **参加（ $j=1$ ）/不参加（ $j=0$ ）** 宴会时，最大的快乐值，初始时 $f_{i, 1}=r_i$。

对于 $u\rightarrow v$，更新完 $v$ 后有

$$
\begin{align*}
f_{u, 1} &\leftarrow f_{u, 1} + f_{v, 0} \\
f_{u, 0} &\leftarrow f_{u, 0} + \max\{f_{v, 1}, f_{v, 0}\}
\end{align*}
$$

</details>

## 二叉苹果树

给一棵二叉树，每条边上有一些苹果。

问保留 $q$ 条边的情况下，最多能留多少苹果。

<details>

设 $f_{i, j}$ 为以 $i$ 为根的子树，保留 $j$ 条边的情况下的最优答案。

对于 $u\stackrel{w}\longrightarrow v$，更新完 $v$ 后有

$$
\begin{align*}
f_{u, i} &= \max\{f_{u, i}, f_{u, i - j - 1} + f_{v, j} + w\}\\ &i:q\rightarrow0，j:i-1\rightarrow0
\end{align*}
$$

转移类似背包，舍弃 $j + 1$ 条边（因为和子节点也是一条边），拿子树留 $j$ 条边的答案。

</details>