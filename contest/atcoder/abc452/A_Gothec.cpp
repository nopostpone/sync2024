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

    string m, d;
    cin >> m >> d;

    auto s = m + d;
    if (s == "17" or s == "33" or s == "55" or s == "77" or s == "99") {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}