#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    int ed = (n % 2 ? (m % 2) : ((m + 1) % 2));
    
    i64 a = (i64)(n + 1) / 2 * ((m + 1) / 2);
    a += (i64)n / 2 * (m / 2);

    i64 b = (i64)n * m - a;

    cout << (((a != b) xor (ed == 0)) ? "YES" : "NO") << "\n";    
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