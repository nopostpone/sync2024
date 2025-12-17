#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }

    using pii = pair<int, int>;
    auto dis = [](pii A, pii B) -> long double {
        auto [x, y] = A;
        auto [u, v] = B;
        return sqrt(1ll * (x - u) * (x - u) + 1ll * (y - v) * (y - v));
    };

    long double ans = 0;
    pair<int, int> now = {0, 0};
    for (auto &[x, y] : a) {
        ans += dis(now, pii{x, y});
        now = {x, y};
    }
    cout << ans + dis(now, pii{0, 0}) << endl;
    
    return 0;
}