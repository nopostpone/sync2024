// https://ac.nowcoder.com/acm/problem/279317
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    DSU dsu(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        dsu.merge(x, y);
    }

    vector<unordered_map<int, int>> s(n);
    for (int i = 0; i < n; i++) {
        s[dsu.find(i)][a[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0, mx = 0;
        for (auto [x, y] : s[i]) {
            mx = max(y, mx);
            sum += y;
        }
        ans += sum - mx;
    }
    cout << ans << endl;
    
    return 0;
}