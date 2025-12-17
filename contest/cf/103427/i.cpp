#include <bits/stdc++.h>
using namespace std;

using C = std::complex<double>;

void solve() {
    array<C, 4> z;
    array<C, 3> w;

    for (int i = 0; i < 3; i++) {
        int p, q;
        cin >> p >> q;
        z[i] = C(p, q);

        cin >> p >> q;
        w[i] = C(p, q);
    }
    {
        int p, q;
        cin >> p >> q;
        z[3] = C(p, q);
    }

    C ans = w[0] - (w[2] - w[0]) / ((z[0] - z[1]) * (z[2] - z[3]) * (w[1] - w[2]) / ((z[0] - z[3]) * (z[1] - z[2]) * (w[0] - w[1])) - C(1, 0));

    cout << ans.real() << " " << ans.imag() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}