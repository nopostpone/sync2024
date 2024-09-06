赛时只做出了 ABC，赛后把剩余的题目补完了，这也是我补完整的第一场比赛，过程曲折，收获颇丰，遂发篇题解记录一下（代码放在最下面）。

![](https://cdn.luogu.com.cn/upload/image_hosting/vcq7y7l0.png)

> WA麻了...

## [A - Cut](https://atcoder.jp/contests/abc368/tasks/abc368_a)

从 $n$ 张卡片底部取 $k$ 张牌放到顶部，只需在改变输出的顺序即可。

## [B - Decrease 2 max elements](https://atcoder.jp/contests/abc368/tasks/abc368_b)

由于数据范围给的很小，直接模拟就可以了。

## [C - Triple Attack](https://atcoder.jp/contests/abc368/tasks/abc368_c)

也是模拟题，需要开 `long long`。

## [D - Minimum Steiner Tree](https://atcoder.jp/contests/abc368/tasks/abc368_d)

对一个非“指定”的节点，如果删去它后形成的两棵子树内，都存在“指定节点”，那么这个点一定不能删去。也就是说，任意两个“指定节点”之间的路径是必须存在的，其他的点就可以删。

那么从任意“指定节点”开始 $\texttt{dfs}$ 遍历整棵树，用类似染色的思路找到所有路径。复杂度 $O(n)$。

## [E - Train Delay](https://atcoder.jp/contests/abc368/tasks/abc368_e)

因为题目要求“原本就可以换乘的线路”，与延时无关，不妨将火车出站和入站分开来看。用一个结构体记录 {时间点，出站还是入站，编号}，其中编号可映射到出站和入站的城市，以这三个变量依次为第一、第二、第三关键字进行排序。

用一个数组记录延时时间，再用一个数组记录所有城市最晚有火车进站的时间，对排序后的结构体数组从头开始遍历。

具体地，如果第 $i$ 列火车在城市 $a$ 出站，那出站时间至少要到 $a$ 最晚有火车进站的时间；如果第 $j$ 列火车在城市 $b$ 进站，同理，可更新 $b$ 的最晚进站时间，这样层层推进，最终记录延时时间的数组就是答案。复杂度 $O(n\log n)$。

## [F - Dividing Game](https://atcoder.jp/contests/abc368/tasks/abc368_f)

变种 $\texttt{Nim}$ 游戏，每个数的质因子数量代表石堆中石子的数量。预处理质数筛，对序列每个数分解质因数。复杂度为 $O(nm)$，其中 $m$ 为 $[2, \max a_i]$ 中的素数数量（可用素数定理近似）。

## [G - Add and Multiply Queries](https://atcoder.jp/contests/abc368/tasks/abc368_g)

题目说明了答案不会超过 $10^{18}$，也就是说对于每组询问 $(l, r)$，在数组 $b$ 对应区间内，不能有超过 $\lfloor\log_2{10^{18}}\rfloor=59$ 个大于 $1$ 的数，可以感性理解为 $b$ 数组里有非常多的 $1$。

对于 $b_i = 1$，$v$ 肯定是变成 $v+a_i$ 更优，即这个位置对答案的贡献是 $a_i$。推广到一个包含在询问内的区间 $[x, y]$，若 $b_i=1\ (x \leq i\leq y)$，则这个区间对答案的贡献就是 $\sum_{i=x}^ya_i$。

用树形结构（比如树状数组）维护 $a$ 的区间和；用一个数组统计 $b$ 中大于 $1$ 的元素的下标。

对于询问区间 $[l, r]$，二分找到第一个大于 $l$ 的下标和第一个大于 $r$ 的下标，就可以知道区间内有哪些可直接计算的子区间，这道题就做出来了。复杂度 $O(n\log n\log V)$，其中 $V = 10^{18}$。

## 代码

**[A](https://atcoder.jp/contests/abc368/submissions/57029873) | [B](https://atcoder.jp/contests/abc368/submissions/57042258) | [C](https://atcoder.jp/contests/abc368/submissions/57050694) | [D](https://atcoder.jp/contests/abc368/submissions/57097152) | [E](https://atcoder.jp/contests/abc368/submissions/57460629) | [F](https://atcoder.jp/contests/abc368/submissions/57414702) | [G](https://atcoder.jp/contests/abc368/submissions/57468251)**


