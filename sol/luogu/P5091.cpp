#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int phi(int n) {
    int x = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            x = x / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        x = x / n * (n - 1);
    return x;
}

template <class T>
T power(int a, T b, T p) {
    T res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int a, m;
    cin >> a >> m;

    const int p = phi(m);

    string s;
    cin >> s;

    int b{};
    bool flag{};
    for (auto c : s) {
        b = b * 10 + (c - '0');
        if (b >= p) {
            flag = true;
            b %= p;
        }
    }
    if (flag) {
        b += p;
    }

    cout << power(a, b, m);

    return 0;
}