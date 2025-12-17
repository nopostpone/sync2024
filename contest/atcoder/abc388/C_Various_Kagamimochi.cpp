#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    ll ans{};
    for (auto x : a) {
        ans += upper_bound(a.begin(), a.end(), x / 2) - a.begin();
    }
    cout << ans << "\n";

    return 0;
}