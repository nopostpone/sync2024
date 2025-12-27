#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> stk;
    for (auto x : a) {
        stk.push_back(x);

        int t = stk.size();
        if (t > 3 and stk[t - 1] == stk[t - 2] and stk[t - 2] == stk[t - 3] and stk[t - 3] == stk[t - 4]) {
            for (int i = 0; i < 4; i++) {
                stk.pop_back();
            }
        }
    }
    cout << stk.size() << "\n";

    return 0;
}