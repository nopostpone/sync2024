#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    array<vector<string>, 6> f;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        f[s.size()].push_back(s);
    }
    ll ans{};
    for (int x = 1; x <= 5; x++) {
        for (int y = 1; y <= 5; y++) {
            if ((x + y) % 2 == 1) {
                continue;
            }
            int h = (x + y) / 2;

            array<int, 92> cnt{};
            for (auto a : f[x]) {
                int s = 45;
                for (int i = 0; i < x; i++) {
                    if (i < h) {
                        s += a[i] - '0';
                    } else {
                        s -= a[i] - '0';
                    }
                }
                cnt[s] += 1;
            }
            for (auto a : f[y]) {
                int s = 45;
                for (int i = 0; i < y; i++) {
                    if (x + i >= h) {
                        s += a[i] - '0';
                    } else {
                        s -= a[i] - '0';
                    }
                }
                ans += cnt[s];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}