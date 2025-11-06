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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int me = a[0];

    ranges::sort(a);
    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        if (b[i] <= me) {
            c[i] = 1;
        } else {
            c[i] = a.end() - (lower_bound(a.begin(), a.end(), b[i])) + 1;
        }
    }
    ranges::sort(c);
    RMQ<int, greater<int>> rmq(c);
    
    for (int i = 1; i <= m; i++) {
        ll ans{};
        for (int j = 0; j + i <= m; j += i) {
            ans += rmq(j, j + i);
        }
        cout << ans << " \n"[i == m];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}