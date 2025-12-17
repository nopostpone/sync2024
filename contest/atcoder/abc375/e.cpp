#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ranges::sort(b, greater<>());
    array<int, 3> s;

    bool ok = true;
    auto dfs = [&](auto &&self, int dep) {
        if (dep == n) {

        }
    };

    return 0;
}