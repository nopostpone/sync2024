#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int N = 1e5;

struct Node {
    int son[2];
    int cnt;
} t[30 * N];

int tot, root;

void insert(int x) {
    int u = root;
    for (int i = 29; i >= 0; i--) {
        int b = x >> i & 1;

        if (not t[u].son[b]) {
            t[u].son[b] = tot++;
            t[tot].son[0] = t[tot].son[1] = t[tot].cnt = 0;
        }
        u = t[u].son[b];
        t[u].cnt++;
    }
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
