#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int need[] = {0, 3, 2, 1};

    array<int, 4> s{};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s[a]++;
    }

    int ans = inf;
    for (int i = 0; i < 4; i++) {
        int cost = s[(i + 1) % 4] + 2 * s[(i + 2) % 4] + 3 * s[(i + 3) % 4];
        ans = min(ans, cost + need[(cost + i) % 4]);
    }
    cout << ans << "\n";

    return 0;
}