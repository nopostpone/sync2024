#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int query(int x) {
    cout << "? " << x << endl;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

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