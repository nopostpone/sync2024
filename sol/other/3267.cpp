// https://www.spoj.com/problems/DQUERY/
#include <bits/stdc++.h>
#ifdef LOCAL
#pragma GCC optimize(2)
#endif
using namespace std;
using ll = long long;

constexpr int N = 1e6 + 5;

int idx[N];
int n, a[N], cnt[N];
int lpos, rpos, now;

void add(int pos) {
}

struct Q {
    int l, r, id;
    bool operator<(const Q &o) const {
        return (idx[l] ^ idx[o.l]) ? idx[l] < idx[o.l] : ((idx[l] & 1) ? r < o.r : r > o.r);
    }
};

void solve() {
    cin >> n;
    int len = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[i] = (i - 1) / len + 1;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}