#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    if (m >= n or m < n - 26) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    auto s = string(n, 'a');

    for (int i = 0; i < n; i++) {
        s[i] += (i % 26);
    }
    if (26 <= n and n < 52) {
        s.back() = s[m - 1];
    } else {
        s[n - m] = s[0];
    }
    

    cout << s << "\n";

    {
        int ans = 0;

        {
            set<int> st;
            for (int i = n - 1; ~i; i--) {
                if (st.contains(s[i])) {
                    ans = max(ans, i + 1);
                    break;
                }
                st.insert(s[i]);
            }
        }
        {
            set<int> st;
            for (int i = 0; i < n; i++) {
                if (st.contains(s[i])) {
                    ans = max(ans, n - i);
                    break;
                }
                st.insert(s[i]);
            }
        }
        assert(ans == m);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}