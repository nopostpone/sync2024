#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    i64 n;
    cin >> n;

    constexpr auto check = [](i64 x) {
        i64 sqrtx = std::sqrt(x);
        while (sqrtx * sqrtx > x) {
            sqrtx--;
        }
        return sqrtx * sqrtx == x;
    };

    vector<i64> ans;
    while (not check(n)) {
        i64 x = (n & -n);
        ans.push_back(x);
        n += x;
    }

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
6 2
3 2 4 5 3 6
2
2 4
3 6
*/