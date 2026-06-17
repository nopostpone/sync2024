#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;
namespace vew = std::views;

constexpr int V = 1e6;
constexpr int inf = 2e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> p(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    int pm = rgs::min(p);
    int cm = rgs::min(c);
    int sm = rgs::min(vew::zip_transform(std::plus(), p, c));

    int m;
    std::cin >> m;

    std::vector<int> tp(m), tc(m), d(m);
    for (int i = 0; i < m; i++) {
        std::cin >> tp[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> tc[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> d[i];
    }

    std::vector<int> minC(V + 1, inf), minP(V + 1, inf);
    for (int i = 0; i < n; i++) {
        minC[p[i]] = std::min(minC[p[i]], c[i]);
        minP[c[i]] = std::min(minP[c[i]], p[i]);
    }
    for (int i = 1; i <= V; i++) {
        minC[i] = std::min(minC[i], minC[i - 1]);
        minP[i] = std::min(minP[i], minP[i - 1]);
    }

    for (int i = 0; i < m; i++) {
        int A = inf;
        if (tp[i] != 0 and tc[i] != 0 and minP[tc[i] - 1] < tp[i]) {
            A = 0;
        } else {
            A = sm;
            if (tc[i] != 0) {
                A = std::min(A, minP[tc[i] - 1]);
            }
            if (tp[i] != 0) {
                A = std::min(A, minC[tp[i] - 1]);
            }
        }

        int B = (pm < tp[i] ? 0 : pm) + tc[i] + d[i];
        int C = (cm < tc[i] ? 0 : cm) + tp[i] + d[i];
        int D = tp[i] + tc[i] + 2 * d[i];

        std::cout << std::min({A, B, C, D}) << "\n";
    }
}
