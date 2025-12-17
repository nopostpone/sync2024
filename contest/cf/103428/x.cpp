#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("1.in", "w", stdout);
    mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};

    int n = 100000;
    int k = 100;

    cout << n << " " << k << " " << 0 << "\n";
    for (int i = 0; i < n; i++) {
        cout << rng() % 100000 << " \n"[i == n - 1];
    }

    return 0;
}