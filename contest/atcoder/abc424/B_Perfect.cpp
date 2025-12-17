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

    int n, m, k;
    cin >> n >> m >> k;

    vector<array<bool, 10>> f(n);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        f[a][b] = true;

        if (ranges::count(f[a], true) == m) {
            ans.push_back(a + 1);
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }


    return 0;
}