#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

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
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> B; // idx not 1
    for (int i = 0; i < n; i++) {
        if (b[i] > 1) {
            B.push_back(i);
        }
    }

    Fenwick<ll> A(n);
    for (int i = 0; i < n; i++)
        A.add(i, a[i]);

    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 3) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            
            auto itS = upper_bound(B.begin(), B.end(), l);
            auto itE = upper_bound(B.begin(), B.end(), r);
            if (itS == B.end()) {
                cout << A.rangeSum(l, r + 1) << endl;
                continue;
            } else if (*itS > r) {
                cout << A.rangeSum(l, r + 1) << endl;
                continue;
            }

            ll ans = 0;
            int x = l, y;
            for (auto it = itS; it != itE; it++) {
                y = *it;
                ans += A.rangeSum(x, y);
                ans = max<ll>(ans + a[y], ans * b[y]);
                x = y + 1;
            }
            ans += A.rangeSum(x, r + 1);
            cout << ans << endl;

        } else {
            int i, x;
            cin >> i >> x;
            i--;
            if (op == 1) {
                A.add(i, -a[i]);
                a[i] = x;
                A.add(i, a[i]);

            } else {

                if (b[i] > 1) {
                    B.erase(lower_bound(B.begin(), B.end(), i));
                }
                b[i] = x;
                if (b[i] > 1) {
                    B.insert(lower_bound(B.begin(), B.end(), i), i);
                }
            }
        }
    }

    return 0;
}