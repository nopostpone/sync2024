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

    int n;
    string s;
    cin >> n >> s;

    int c1 = ranges::count(s, '1');
    int c6 = ranges::count(s, '6');

    cout << min(c6 - 1, c1) << endl;

    return 0;
}