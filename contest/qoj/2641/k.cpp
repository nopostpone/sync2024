#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

using P = pair<i64, i64>;

constexpr istream &operator>>(istream &is, P &p) {
    return is >> p.first >> p.second;
}
constexpr P operator+(P a, P b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}
constexpr P operator-(P a, P b) {
    a.first -= b.first;
    a.second -= b.second;
    return a;
}
constexpr P operator*(int x, P a) {
    a.first *= x;
    a.second *= x;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    s--;

    vector<P> a(n), b(n);
    P suma {}, sumb {};
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        suma = suma + a[i];
        sumb = sumb + b[i];
    }

    suma = suma - 2 * a[s];

    for (int i = 0; i < n; i++) {
        if (sumb - 2 * b[i] == suma) {
            cout << i + 1 << "\n";
            break;
        }
    }
}

/*
3 1
6 3 2 3
4 3 2 1
3 4 1 6
*/