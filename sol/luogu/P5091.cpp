#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    a %= m;
    int mm = m;

    int phi = 1;
    for (int i = 2; i * i <= mm; ++i) {
        if (mm % i) {
            continue;
        }

        phi *= i - 1;
        mm /= i;

        while (mm % i == 0) {
            phi *= i;
            mm /= i;
        }
    }
    if (mm > 1)
        phi *= mm - 1;

    string s;
    cin >> s;

    int bm{};
    bool flag{};
    for (auto c : s) {
        bm = bm * 10 + (c - '0');
        if (bm >= phi) {
            flag = true;
        }
        bm %= phi;
    }
    if (flag) {
        bm += phi;
    }

    cout << power(a, bm, m);

    return 0;
}