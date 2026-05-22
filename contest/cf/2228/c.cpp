#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    u64 a;
    int n;
    std::cin >> a >> n;

    std::string sa = std::to_string(a);

    int L = sa.size();

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    u64 ans = std::numeric_limits<u64>::max();

    if (L > 1) {
        u64 b = 0;
        for (int i = 0; i < L - 1; i++) {
            b = 10 * b + d.back();
        }
        ans = std::min(ans, a - b);
    }
    {
        u64 b = 0;
        if (d.front() == 0 and d.size() > 1) {
            b = d[1];
        } else {
            b = d[0];
        }
        for (int i = 0; i < L; i++) {
            b = 10 * b + d.front();
        }
        ans = std::min(ans, b - a);
    }
    {
        std::vector<u64> cand;

        u64 pre = 0;
        for (int i = 0; i < L; i++) {
            int c = sa[i] - '0';
            int x = -1;
            for (auto v : d) {
                if (v < c) {
                    x = std::max(x, v);
                }
            }
            if (x != -1) {
                u64 b = pre * 10 + x;
                for (int j = i + 1; j < L; j++) {
                    b = b * 10 + d.back();
                }
                cand.push_back(b);
            }

            x = 10;
            for (auto v : d) {
                if (v > c) {
                    x = std::min(x, v);
                }
            }
            if (x != 10) {
                u64 b = pre * 10 + x;
                for (int j = i + 1; j < L; j++) {
                    b = b * 10 + d.front();
                }
                cand.push_back(b);
            }

            if (std::binary_search(d.begin(), d.end(), c)) {
                pre = pre * 10 + c;
            } else {
                break;
            }
            if (i == L - 1) {
                cand.push_back(pre);
            }
        }
        for (auto b : cand) {
            u64 d = 0;
            if (b < a) {
                d = a - b;
            } else {
                d = b - a;
            }
            ans = std::min(ans, d);
        }
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