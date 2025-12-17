#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const int logn;

    const Cmp cmp = Cmp();
    std::vector<std::vector<T>> jump;

    constexpr RMQ(const std::vector<T> &a)
        : n{a.size()}, logn{std::__lg(n)}, jump(logn + 1) {

        jump[0] = a;

        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }

        for (int j = 0; j < logn; j++) {
            const int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = std::min(jump[j][i], jump[j][i + (1 << j)], cmp);
            }
        }
    }

    constexpr T operator()(int l, int r) const {
        int log = std::__lg(r - l);
        return std::min(jump[log][l], jump[log][r - (1 << log)], cmp);
    }
};

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] - pre[i];
    }
    RMQ<ll, greater<ll>> rmq(b);

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << "\n";
            continue;
        }
        l--;
        ll ans = rmq(l + 1, r);
        cout << max(0ll, ans + pre[l]) << "\n";
    }

    return 0;
}