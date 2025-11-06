#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int P = 1000000007;
int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = 1ll * a * a % P) {
        if (b & 1) {
            res = 1ll * res * a % P;
        }
    }
    return res;
}
int inv(int x) {
    return power(x, P - 2);
}

int norm(int x) {
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
    assert(0 <= x and x < P);
    return x;
}
void add(int &x, int y) {
    x = norm(x + norm(y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
    invfac[n] = inv(fac[n]);
    for (int i = n; i > 0; i--) {
        invfac[i - 1] = 1ll * invfac[i] * i % P;
    }

    auto binom = [&](int n, int m) -> int {
        if (n < m or m < 0) {
            return 0;
        }
        return 1ll * (1ll * fac[n] * invfac[n - m] % P) * invfac[m] % P;
    };

    int L, R;
    cin >> L >> R;

    int ans = 0;
    if (L == 1) {
        ans += n;
    } else if (L == 2) {
        ans += n;
        ans += n - 1;
    }
    L = max(L, 3);

    vector<int> cache(n, -1);
    for (int i = 0; i < n; i++) {
        int d = adj[i].size();
        if (cache[d] == -1) {
            int res = 0;
            for (int j = L; j <= R; j++) {
                add(res, binom(d, j - 1));
            }
            cache[d] = res;
        }
        add(ans, cache[d]);
    }
    cout << ans << "\n";

    return 0;
}