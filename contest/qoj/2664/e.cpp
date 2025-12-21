#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> w(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return r[i] > r[j];
    });

    auto check = [&](int m) {
        priority_queue<int> q;
        i64 sum = 0;

        for (int i : ord) {
            if (q.size() == m) {
                sum -= q.top();
                q.pop();
            }

            sum += w[i];
            q.push(w[i]);

            if (q.size() == m and (i64)m * r[i] >= sum) {
                return true;
            }
        }

        return false;
    };
    
    int lo = 0, hi = n;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    cout << lo << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
2
5
1 2 3 4 5
5 4 3 2 1
10
3 1 4 1 5 9 2 6 5 3
5 8 9 7 9 3 2 3 8 4
*/
