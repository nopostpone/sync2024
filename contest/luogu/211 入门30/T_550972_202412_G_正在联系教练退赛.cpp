#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int m;
    cin >> m;

    vector<string> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    for (auto &&now : s) {
        bool ok = true;
        for (auto &&tar : t) {
            if (now.find(tar) != string::npos) {
                ok = false;
            }
        }
        cout << (ok ? "No" : "Yes") << "\n";
    }
    
    return 0;
}