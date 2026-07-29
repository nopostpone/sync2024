#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

using p32 = std::pair<int, int>;

constexpr int inf = 1e9;

auto work(auto &a) {
    rgs::sort(a);

    // std::cerr << "work: \n";
    // for (auto [l, r] : a) {
    //     std::cerr << l << " " << r << "\n";
    // }
    std::vector<p32> res;
    for (auto [l, r] : a) {
        if (res.empty() or res.back().second > r) {
            res.emplace_back(l, r);
        }
    }

    // std::cerr << a.size() << " " << res.size() << "\n";

    return std::move(res);
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<p32>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    std::vector<int> ans(n, inf);
    // std::vector<std::vector<p32>> dp(n);

    auto merge = [&](const auto &a, const auto &b) {
        std::vector<p32> res;
        for (int i = 0, j = 0; i < a.size() and j < b.size(); ) {
            auto [la, ra] = a[i];
            auto [lb, rb] = b[j];

            res.emplace_back(std::max(la, lb), std::max(ra, rb));
            if (ra > rb) {
                i++;
            // } else {
            //     j++;
            // }
            } else if (ra < rb) {
                j++;
            } else {
                i++;
                j++;
            }

            // std::cerr << i << " " << j << " " << res.size() << "\n";
        }
        return work(res);
    };

    
    auto dfs = [&](auto &&self, int x, int p) -> std::vector<p32> {

        std::queue<std::vector<p32>> fs;
        fs.push({{}});
        for (auto [y, w] : adj[x]) {
            if (y == p) {
                continue;
            }
            auto g = self(self, y, x);

            std::vector<p32> f;
            for (auto [l, r] : g) {
                f.emplace_back(std::max(0, l - w), r + w);
                f.emplace_back(l + w, std::max(0, r - w));
            }
            fs.push(work(f));
        }
        while (fs.size() > 1) {
            auto a = fs.front();
            fs.pop();
            auto b = fs.front();
            fs.pop();
            fs.push(merge(a, b));
        }

        for (auto [l, r] : fs.front()) {
            ans[x] = std::min(ans[x], l + r);
        }
        return std::move(fs.front());
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
