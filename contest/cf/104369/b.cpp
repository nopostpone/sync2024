#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int P = 998244353;
int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = (i64)a * a % P) {
        if (b & 1) {
            res = (i64)res * a % P;
        }
    }
    return res;
}
void add(int &x, int y) {
    x += y;
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
}

mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};
constexpr int base = 4567;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    
    vector<int> f(n + 1, 1);
    for (int i = 0, x; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        do {
            x = rng() % (int)1e9 + (int)1e9;
        } while (x == 0);
        f[l] = 1ll * f[l] * x % P;
        f[r] = 1ll * f[r] * x % P;
    }
    for (int i = 0; i < n; i++) {
        f[i + 1] = 1ll * f[i + 1] * f[i] % P;
    }
    for (int i = 0; i <= n; i++) {
        cerr << f[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
/*
2
5
3 2 4 1 100
3
1 3
2 4
5 5
5
7 3 4 2 2
3
1 4
2 3
4 5


*/