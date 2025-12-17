#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

template <class U>
struct LinearBasis {
    int n, m;
    std::vector<U> a, b;
    LinearBasis() : n{0}, m{0} {}
    LinearBasis(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        this->m = 0;
        a.assign(n, {});
        b.assign(n, {});
    }
    void insert(U x) {
        U y = x;
        for (int i = n - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (a[i] == U()) {
                    a[i] = x;
                    b[i] = y;
                    m++;
                    return;
                }
                x ^= a[i];
            }
        }
    }
    bool contains(U x) {
        for (int i = n - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (a[i] == U()) {
                    return false;
                }
                x ^= a[i];
            }
        }
        return true;
    }
    int size() {
        return m;
    }
    int rank() {
        return n - m;
    }
    U &operator[](int x) {
        return b[x];
    }
    const U &operator[](int x) const {
        return b[x];
    }
};
using L32 = LinearBasis<u32>;
using L64 = LinearBasis<u64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a, greater());
    
    for (int d = 18; d >= 0; d--) {
        L32 base(d);
        for (int i = 0; i < n; i++) {
            if (a[i] < (1 << d)) {
                base.insert(a[i]);
            }
        }
        if (base.size() != d) {
            continue;
        }

        vector<int> p, vis(1 << d);
        [&](this auto &&self, int x) -> void {
            p.push_back(x);
            vis[x] = true;
            for (int i = 0; i < d; i++) {
                if (not vis[x ^ base[i]]) {
                    self(x ^ base[i]);
                }
            }
        }(0);
        cout << d << "\n";
        for (int i = 0; i < 1 << d; i++) {
            cout << p[i] << " \n"[i == (1 << d) - 1];
        }
        break;
    }

    return 0;
}