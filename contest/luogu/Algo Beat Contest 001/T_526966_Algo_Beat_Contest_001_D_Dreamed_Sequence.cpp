#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int P = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    unordered_map<i64, int> f;
    for (int i = 0; i < n; i++) {
        unordered_set<i64> tem;
        for (int j = 0; j < n; j++) {
            i64 now = a[i] * b[j];
            now %= P;
            tem.insert(now);
        }
        for (auto x : tem) {
            f[x]++;
        }
    }

    i64 ans = 0;
    for (auto [x, y] : f) {
        cerr << x << " " << y << endl;
        ans = max<i64>(ans, y);
    }

    cout << ans << "\n";

    return 0;
}