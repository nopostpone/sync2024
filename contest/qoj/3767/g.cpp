#include <bits/stdc++.h>
#include <queue>

using i64 = long long;

namespace rgs = std::ranges;

void solve() {
    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> f;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;

        f[a].push_back(b);
    }
    std::vector vf(f.begin(), f.end());

    std::priority_queue<int> mul;
    i64 ans = 0;

    for (auto &[i, v] : vf) {
        if (not f.contains(i - 1)) {
            while (not mul.empty()) {
                mul.pop();
            }
        }
        rgs::sort(v, std::greater());

        std::priority_queue<int> nmul;
        for (auto x : v) {
            if (not mul.empty()) {
                i64 m = mul.top();
                mul.pop();
                ans += x * m;

                nmul.push(m + 1);
            } else {
                ans += x;
                nmul.push(2);
            }
        }
        mul = std::move(nmul);

        // std::cerr << i << " " << ans << "\n";
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}

/*
2
9
1 3
3 10
6 4
1 2
5 8
0 5
2 7
6 1
2 7
1
1000000000 1000000

1
2
999999999 1233
1000000000 1234

1
10
1 5 1 5 1 5 1 5
2 4 2 4
3 10 3 10 3 1 3 1

*/