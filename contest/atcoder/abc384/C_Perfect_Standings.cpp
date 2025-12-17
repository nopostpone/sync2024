#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    const int n = 5;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, char> f;
    f[0] = 'A';
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] + 1;
    }

    map<int, set<string>> g;

    for (int i = 1; i < 32; i++) {
        int s{};
        string now{};
        for (int j = 0; j < 5; j++) {
            if ((i >> j) & 1) {
                now += f[j];
                s += a[j];
            }
        }
        g[s].insert(now);
    }

    for (auto it = g.rbegin(); it != g.rend(); it++) {
        for (auto i : it->second) {
            cout << i << "\n";
        }
    }
    
    return 0;
}