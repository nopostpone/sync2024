#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    string s[3];
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    if (s[0].size() != s[1].size()) {
        cout << "NO\n";
        return;
    }
    if (s[0].size() != s[2].size()) {
        cout << "YES\n";
        return;
    }

    DSU dsu(26);
    int tot = 0;
    for (int i = 0; i < s[0].size(); i++) {
        int x = s[0][i] - 'a';
        int y = s[1][i] - 'a';
        dsu.merge(x, y);
    }

    bool same = true;
    for (int i = 0; i < s[2].size(); i++) {
        same &= dsu.same(s[2][i] - 'a', s[0][i] - 'a');
    }
    cout << (!same ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}