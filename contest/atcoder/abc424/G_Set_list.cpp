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

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a);

    vector<int> b(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i] >> c[i];
    }

    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    ranges::sort(ord, [&](int i, int j) {
        return pair(b[i], c[i]) > pair(b[j], c[j]);
    });

    

    return 0;
}