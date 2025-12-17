#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using f64 = long double;

constexpr double eps = 1e-8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](f64 x) {
        f64 sum = 0;
        for (int i = 0; i < n; i++) {
            f64 t = x * a[i];
            sum += t / (1 + t);
        }
        return sum >= k;
    };

    f64 lo = 0, hi = 1e15;
    for (int _ = 0; _ < 200; _++) {
        f64 x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x;
        }
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        f64 x = lo * a[i];
        cout << x / (1 + x) << "\n";
    }
}

/*
3 2
5 5 5

2 1
1 4

4 2
1 2 3 4
*/