#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int P = 998244353;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = i64(a) * a % P) {
        if (b & 1) {
            res = i64(res) * a % P;
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

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        int num, den;
        cin >> num >> den;
        int invden = inv(den);
        p[i] = i64(num) * invden % P;
        q[i] = i64(den - num) * invden % P;
    }

    int u = 1, v = 0, w = 0;
    for (int i = 0; i < n; i++) {
        add(w, u);
        add(v, i64(u) * p[i] % P);
        u = i64(u) * q[i] % P;
    }

    int ans = i64(w) * inv(norm(1 - v)) % P;
    cout << ans << "\n";

    return 0;
}