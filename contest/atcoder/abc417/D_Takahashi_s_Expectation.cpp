#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;
constexpr int V = 5e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> a[i] >> b[i];
    }

    array<int, V> dp{};
    

    return 0;
}