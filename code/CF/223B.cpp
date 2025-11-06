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

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> l(n + 1), r(n + 1, n);
    array<int, 26> p{};

    p.fill(-1);
    for (int i = 0, j = 0; i < n; i++) {
        int x = s[i] - 'a';

        if (j < m and s[i] == t[j]) {
            p[x] = j;
            j++;
        }
        l[i] = p[x];
    }

    p.fill(m);
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        int x = s[i] - 'a';

        if (j >= 0 and s[i] == t[j]) {
            p[x] = j;
            j--;
        }
        r[i] = p[x];
    }

    bool ok = not ranges::any_of(views::iota(0, n), [&](int i) {
        return l[i] < r[i];
    });

    cout << (ok ? "Yes" : "No") << "\n"; 

    return 0;
}