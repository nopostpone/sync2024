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

    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    multiset<pair<i64, int>> s;
    
    i64 cur = 0;
    int rest = k;
    for (int i = 0; i < n; i++) {
        while (c[i] > rest) {
            auto [t, j] = *s.begin();
            cur = max(cur, t);
            rest += c[j];
            
            s.erase(s.begin());
        }

        rest -= c[i];
        cur = max(cur, (i64)a[i]);
        s.emplace(cur + b[i], i);

        cout << cur << "\n";
    }

    return 0;
}