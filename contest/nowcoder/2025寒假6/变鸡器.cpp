#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

string t = "CHICKEN";

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> f(26);
    for (int i = 0; i < n; i++) {
        f[s[i] - 'A']++;
    }
    for (int i = 0; i < 7; i++) {
        f[t[i] - 'A']--;
    }
    
    int p = 0;
    for (int i = 0; i < 7; i++) {
        int q = s.find(t[i], p);
        if (q == -1) {
            cout << "NO\n";
            return;
        } else {
            p = q;
        }
    }

    int del = n - 7;
    bool ok = false;
    if (del % 2 == 0) {
        ok = true;
        for (int i = 0; i < 26; i++) {
            if (f[i] > del / 2) {
                ok = false;
            }
        }
    }
    
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}