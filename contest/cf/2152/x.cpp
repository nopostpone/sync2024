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

    mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};

    int n;
    cin >> n;

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        auto x = rng() % int(1e9);
        cout << x << " ";
    }

    return 0;
}