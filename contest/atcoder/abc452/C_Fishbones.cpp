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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        b[i]--;
    }

    int m;
    cin >> m;

    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[j].size() != a[i]) {
                continue;
            }
            f[i] |= 1 << (s[j][b[i]] - 'a');
        }
    }

    for (int i = 0; i < m; i++) {
        if (s[i].size() != n) {
            cout << "No\n";
            continue;
        }
        bool found = true;
        for (int j = 0; j < n; j++) {
            found &= (f[j] >> (s[i][j] - 'a'));
        }
        cout << (found ? "Yes" : "No") << "\n";
    }
}