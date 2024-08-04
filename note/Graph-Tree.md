# 记录不会做的树题

## [洛谷【MX-J2-T3】Piggy and Trees](https://www.luogu.com.cn/problem/P10842)

给你一棵 $n$ 个结点的树。

定义 $f(u, v, i)$ 为，在所有满足 $^\dagger\text{dis}(u, x) + \text{dis}(v, x) = \text{dis}(u, v)$ 的点 $x$ 中，$\text{dis}(x, i)$ 的最小值。

求 $\sum\limits_{u = 1}^n \sum\limits_{v = u + 1}^n \sum\limits_{i = 1}^n f(u, v, i)$ 对 $10^9 + 7$ 取模的值。

$^\dagger\text{dis}(u, v)$ 为树上 $u, v$ 两点的路径长度。特别地，$\text{dis}(u, u) = 0$。

$ 2 \leq n \leq 2 \cdot 10 ^ 5$

_赛时没什么头绪，只想出了对每组 $(u, v)$ 暴力求解，仅拿了第一个任务点。_

解：

<!-- <details> -->

不妨在每条边上设置一个计数器 $c_{x, y}$，统计遍历到这条边的次数，那么答案就是 $\sum\limits_{(x, y) \in E}c_{x,y}$。

尝试计算每条边的贡献：对任意一条边 $x→y$ ，当且仅当 $(u, v)$ 的路径不经过该边，且 $i$ 到 $(u, v)$ 必经过该边，$c_{x, y}$ 增加 $1$。

设断开这条边后形成的两棵树大小为 $\text{siz}_A$ 和 $\text{siz}_B $，则有：

$$
c_{x,y} = \binom {2}{\text{siz}_A} \cdot \binom {1}{\text{siz}_B} + \binom {2}{\text{siz}_B} \cdot \binom {1}{\text{siz}_A}
$$

即
$$
c_{x,y} = \frac{\text{siz}_A\text{siz}_B(\text{siz}_A - 1)(\text{siz}_B - 1)}{2}
$$

枚举答案即可。

</details>