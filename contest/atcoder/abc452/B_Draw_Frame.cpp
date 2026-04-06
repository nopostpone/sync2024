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

    vector s(n, string(m, '.'));
    s[0] = s[n - 1] = string(m, '#');
    for (int i = 1; i < n; i++) {
        s[i].front() = s[i].back() = '#';
    }

    for (auto s : s) {
        cout << s << "\n";
    }
}