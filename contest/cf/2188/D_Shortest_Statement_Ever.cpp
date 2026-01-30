#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int E = 30;

void solve() {
    int x, y;
    cin >> x >> y;

    tuple<int, int, int> ans {INT_MAX, -1, -1};

    auto work = [&](int q) {
        if (x & q == 0) {
            ans = min(ans, tuple(abs(q - y), x, q));
        }
        
        {
            int p = x;
            bool flag = false;
            for (int i = E - 1; i >= 0; i--) {
                if ((p >> i & 1) and (q >> i & 1)) {
                    flag = true;
                    p -= 1 << i;
                }
                if ((~p >> i & 1) and (~q >> i & 1) and flag) {
                    p |= 1 << i;
                }
            }
            ans = min(ans, tuple(abs(p - x) + abs(q - y), p, q));
        }
        {
            int p = x;
            vector<int> stk;
            for (int i = E - 1; i >= 0; i--) {
                if ((q >> i & 1)) {
                    stk.push_back(i);
                }
                if ((p >> i & 1) and (q >> i & 1)) {

                    while (not stk.empty()) {
                        int j = stk.back();
                        stk.pop_back();
                        if ((p >> j & 1) and (q >> j & 1)) {
                            p = ((p >> (j + 1)) + 1) << (j + 1);
                        }
                    }

                    break;
                }
            }
            ans = min(ans, tuple(abs(p - x) + abs(q - y), p, q));
        }
    };

    work(y);

    for (int i = 0; i < E; i++) {
        int ny = ((y >> (i + 1)) + 1) << (i + 1);
        work(ny);
    }

    auto [d, p, q] = ans;
    cout << p << " " << q << "\n";
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