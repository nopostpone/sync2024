#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
    for (auto &x : a) {
        is >> x;
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n - 1), s(n);
    cin >> t >> s;

    int x, y;
    cin >> x >> y;
    x--;
    y--;

    int ans = 0;
    for (int i = x; i <= y; i++) {
        if (i != y) {

            ans += t[i];
        }
        ans += s[i];
    }
    cout << ans << endl;

    return 0;
}