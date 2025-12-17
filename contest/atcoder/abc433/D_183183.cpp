#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int get(i64 x) {
    int w = 0;
    while (x) {
        x /= 10;
        w++;
    }
    return w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    vector<int> s[11] {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        s[get(a[i])].push_back(a[i]);
    }
    for (int w = 1; w < 10; w++) {
        sort(s[w].begin(), s[w].end());
    }

    map<i64, int> f[11] {};
    for (int w = 1; w < 11; w++) {
        for (auto x : s[w]) {
            f[w][x % m]++;
            // cerr << w << " " << x << " " << (x % m) << endl;
        }
    }


    i64 ans = 0;

    for (u64 x : a) {
        for (int w = 1; w < 11; w++) {
            x *= 10;
            // cerr << x << endl;
            u64 tar = (x + m - 1) / m;
            tar = tar * m - x;
            // if (w == 10) {
            //     cerr << x << " " << tar << endl;
            // }

            if (f[w].contains(tar)) {
                ans += f[w][tar];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}