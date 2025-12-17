#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

template<typename T>
constexpr T power(T a, ll b) {
    T res {1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    ll l, r;
    cin >> l >> r;

    auto work = [](ll x) -> ll {
        vector<int> a;
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
        reverse(a.begin(), a.end());
        const int n = a.size();

        ll res{};

        // 1
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[0]) {
                ok = false;
                break;
            }
        }
        res += ok;

        // 2
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[0]) {
                break;
            }
            res += power<ll>(a[0], n - i - 1);
        }
    };

    cout << work(r) - work(l - 1) << endl;

    return 0;
}