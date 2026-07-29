#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<int>(m));

    std::vector<std::vector<std::pair<int, int>>> vec(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            a[i][j]--;

            vec[a[i][j]].emplace_back(i, j);
        }
    }

    

    std::vector vis(n + 1, std::vector<int>(m + 1));
}