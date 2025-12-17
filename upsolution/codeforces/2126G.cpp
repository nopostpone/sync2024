#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
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
    int n;
    cin >> n;

    vector<int> a(n), f(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        f[a[i]]++;
    }
    for (int i = 1; i < n; i++) {
        f[i] += f[i - 1];
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[--f[a[i]]] = i;
    }

    DSU fl(n + 1), fr(n + 1);
    int ans = 0, cur = n;

    ranges::reverse(p);
    for (auto i : p) {
        for (int $ = 0; $ < 2; $++) {
            int x = fl.find(i + 1);
            if (x) {
                fl.merge(x - 1, x);
                cur = min(cur, a[x - 1]);
            }

            x = fr.find(i);
            if (x < n) {
                fr.merge(x + 1, x);
                cur = min(cur, a[x]);
            }
        }
        ans = max(ans, a[i] - cur);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}