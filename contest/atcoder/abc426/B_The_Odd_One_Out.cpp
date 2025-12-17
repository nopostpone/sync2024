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

    string s;
    cin >> s;

    if (ranges::count(s, s[0]) == 1) {
        cout << s[0] << "\n";
    } else {
        for (auto c : s) {
            if (c != s[0]) {
                cout << c << "\n";
            }
        }
    }

    return 0;
}