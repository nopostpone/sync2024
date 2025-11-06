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

    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    multiset<int> s(p.begin(), p.end());

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    ranges::sort(ord, [&](int i, int j) {
        return b[i] > b[j] or (b[i] == b[j] and a[i] < a[j]);
    });

    i64 ans = accumulate(p.begin(), p.end(), i64());
    for (auto i : ord) {
        auto it = s.lower_bound(a[i]);
        if (it != s.end()) {
            s.erase(it);
            ans -= b[i];
        }
    }
    cout << ans << "\n";

    return 0;
}