#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    string s;
    cin >> s;

    if (s.back() == '2') {
        cout << s << " " << 2 << "\n";
        return;
    }
    int cnt = ranges::count(s, '1');
    if (cnt == s.size()) {
        if (s.size() % 2 == 1) {
            s.pop_back();
        }
        cout << s << " " << 11 << "\n";
        return;
    } else {
        int x = 0;
        for (auto c : s) {
            x += c - '0';
        }
        x %= 3;
        if (x == 0) {
        } else if (x == 1) {
            s.erase(s.begin() + s.find('1'));
        } else {
            s.erase(s.begin() + s.find('2'));
        }
        cout << s << " " << 3 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}