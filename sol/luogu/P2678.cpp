// https://www.luogu.com.cn/problem/P2678
// 二分经典例题
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, N, M;
    cin >> L >> N >> M;

    vector<int> a(N + 2);
    a[0] = 0, a[N + 1] = L;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    auto check = [&](int d) {
        int cnt = 0;
        int pre = 0;
        for (int i = 1; i <= N + 1; i++) {
            if (a[i] - a[pre] < d) {
                cnt++;
            } else {
                pre = i;
            }
        }
        return cnt <= M;
    };

    int lo = 1, hi = L;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;
        if (check(m)) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }
    cout << lo << endl;

    return 0;
}