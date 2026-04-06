#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    i64 k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    auto work = [&](i64 k) -> i64 {
        if (k < 0) {
            return {};
        }
        i64 ans = 0;
        i64 sum = 0;
        Fenwick<int> fen(n);

        for (int l = 0, r = 0; l < n; l++) {
            r = max(r, l);
            while (r < n and sum <= k) {
                fen.add(p[r], 1);
                sum += fen.rangeSum(p[r] + 1, n);
                r++;   
            }
            if (sum <= k) {
                ans++;
            }
            ans += r - l - 1;

            sum -= fen.sum(p[l]);
            fen.add(p[l], -1);
        }
        return ans;
    };

    cout << work(k) - work(k - 1) << "\n";
}