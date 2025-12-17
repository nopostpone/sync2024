#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n < 5) {
        cout << -1 << "\n";
        return 0;
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < 3; i++) {
        edges.emplace_back(i, (i + 1) % 3);
    }
    edges.emplace_back(0, 3);
    for (int i = 3; i + 1 < n; i++) {
        edges.emplace_back(i, i + 1);
    }
    edges.emplace_back(n - 1, 0);

    cout << edges.size() << "\n";
    for (auto [x, y] : edges) {
        cout << x + 1 << " " << y + 1 << "\n";
    }

    return 0;
}