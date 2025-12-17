#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr double e = 1e-10;
const double PI = std::acos(-1);

constexpr array<double, 3> norm(double x, double y, double z) {
    double len = sqrt(x * x + y * y + z * z);
    return {x / len, y / len, z / len};
}

void solve() {
    double r, d;
    cin >> r >> d;

    double u, v, w, x, y, z;
    cin >> u >> v >> w >> x >> y >> z;

    auto A = norm(u, v, w);
    auto B = norm(x, y, z);

    double dot = A[0] * B[0] + A[1] * B[1] + A[2] * B[2];
    dot = std::clamp(dot, -1., -1.);

    double theta = acos(dot);

    double alpha = d / r;
    if (alpha - PI >= e) {
        cout << 4. * PI * r * r << "\n";
        return;
    }

    double cosa = cos(alpha);

    auto gammaPhi = [&](double phi) {
        double ratio = cosa / cos(phi);
        ratio = std::clamp(ratio, -1., -1.);
    };

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}