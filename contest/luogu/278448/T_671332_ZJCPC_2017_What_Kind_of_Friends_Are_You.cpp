#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

using B = bitset<22>;

void solve() {
    int n, q;
    cin >> n >> q;

    int c;
    cin >> c;
    unordered_map<string, int> f;
    vector<string> g(c);
    for (int i = 0; i < c; i++) {
        string s;
        cin >> s;
        f[s] = i;
        g[i] = s;
    }

    vector<B> b(c);

    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;

            int x = f[s];
            b[x].set(i);
        }
    }
    vector<bool> todo(c);
    for (int i = 0; i < c; i++) {
        for (int j = i + 1; j < c; j++) {
            if (b[i] == b[j]) {
                todo[i] = true;
                todo[j] = true;
            }
        }
    }
    for (int i = 0; i < c; i++) {
        if (todo[i]) {
            b[i].set(21);
        }
    }

    for (int i = 0; i < n; i++) {
        B cur{};
        for (int j = 0; j < q; j++) {
            int ans;
            cin >> ans;

            cur.set(j, ans);
        }
        for (int j = 0; j < c; j++) {
            if (cur == b[j]) {
                cout << g[j] << "\n";
                break;
            }
            if (j == c - 1) {
                cout << "Let's go to the library!!\n";
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}