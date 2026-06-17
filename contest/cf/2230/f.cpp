#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;
namespace vew = std::views;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    n++;

    std::vector<std::vector<std::array<int, 3>>> adj(n);
    std::vector<int> val(2 * (n - 1));

    const int logn = std::__lg(n);
    std::vector f(logn + 1, std::vector<int>(n));

    int tot = 0;

    auto get = [&](int x) {
        std::array<int, 3> t {};
        int j = 0;

        for (int i = logn; i >= 1; i--) {
            int tf = f[i][x];
            while (tf > 0 and j < 3) {
                t[j++] = i;
                tf--;
            }
        }

        return t;
    };

    int ans = 1;

    std::vector<int> m2(n), m3(n);

    for (int x = 1; x < n; x++) {
        int p;
        std::cin >> p;
        p--;

        int e1 = tot++;
        int e2 = tot++;

        adj[p].push_back({x, e1, e2});
        adj[x].push_back({p, e2, e1});

        val[e2] = 1;
        f[1][p]++;

        auto [t1, t2, t3] = get(p);

        int ne1 = 1 + (val[e2] >= t2 ? t3 : t2);
        val[e1] = ne1;
        f[ne1][x]++;

        ans = std::max(ans, 1 + t2);

        if (t2 != m2[p] or t3 != m3[p]) {
            m2[p] = t2;
            m3[p] = t3;
            std::queue<int> q;
            q.push(p);

            while (not q.empty()) {
                int x = q.front();
                q.pop();

                for (auto [y, e1, e2] : adj[x]) {
                    int nv = 1 + (val[e2] >= m2[x] ? m3[x] : m2[x]);

                    if (nv > val[e1]) {
                        int ov = val[e1];
                        val[e1] = nv;

                        if (ov > 0) {
                            f[ov][y]--;
                        }
                        f[nv][y]++;

                        auto [yt1, yt2, yt3] = get(y);
                        ans = std::max(ans, 1 + yt2);

                        if (yt2 != m2[y] or yt3 != m3[y]) {
                            m2[y] = yt2;
                            m3[y] = yt3;
                            q.push(y);
                        }
                    }
                }
            }
        }

        std::cout << ans << " \n"[x == n - 1];
    }
}
