# P1080 国王游戏
# 用py3可以不用手写高精度
import sys


class ren(object):
    def __init__(self, l, r):
        self.l = l
        self.r = r

    def __repr__(self):
        return repr((self.l, self.r))


n = int(input())
huangdizuo, huangdiyou = map(int, sys.stdin.readline().split())
res = [ren(0, 0) for i in range(n)]

for i in range(n):
    res[i].l, res[i].r = map(int, sys.stdin.readline().split())

res = sorted(res, key=lambda ren: ren.l * ren.r)
mmax = huangdizuo // res[0].r
prod = huangdizuo

for i in range(1, n):
    prod *= res[i - 1].l
    mmax = max(mmax, prod // res[i].r)

print(mmax)
