#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string s;
    cin >> s;

    const int n = s.size();

    bool ok = true;
    if (n % 2 == 1) {
        ok = false;
    } else {
        for (int i = 0; i < n and ok; i += 2) {
            if (s[i] != s[i + 1]) {
                ok = false;
            }
        }
        unordered_map<char, int> f;
        for (auto i : s) {
            f[i]++;
        }
        for (auto [x, y] : f) {
            if (y > 2) {
                ok = false;
            }
        }
    }

    cout << (ok ? "Yes" : "No");
    
    return 0;
}