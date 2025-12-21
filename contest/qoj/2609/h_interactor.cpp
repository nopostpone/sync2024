#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

using B = bitset<32>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto query = [&](int x) {
        cout << "? " << setw(10) << x << " ";
        cout << B(x) << endl;
        int ans = 0;
        for (auto y : a) {
            ans = max(ans, x ^ y);
        }
        cout << "->" << setw(10) << (ans ^ x) << " ";
        cout << B((ans ^ x)) << endl;
        return ans;
    };

    [&]() {
        vector<int> ans;
        vector<pair<int, int>> stk;

        auto a0 = query(0);
        stk.emplace_back(30, a0);
        ans.push_back(a0);

        while (ans.size() < n) {
            auto [e, a] = stk.back();
            stk.pop_back();

            auto x = a ^ ((1 << 30) - (1 << e));
            auto b = x ^ query(x);

            if (a != b) {
                int ne = 31 - __builtin_clz(a ^ b);

                stk.emplace_back(ne, a);
                stk.emplace_back(ne, b);
                ans.push_back(b);
            }
        }

        cout << "! ";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } ();
    
    return 0;
}

/*
5
10000 1 2 3 4

8
1 2 3 4 5 6 7 8
*/