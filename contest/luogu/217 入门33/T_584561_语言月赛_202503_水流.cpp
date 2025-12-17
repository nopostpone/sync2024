#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <typename T>
istream& operator>>(istream &is, vector<T> &a) {
    for (auto &x : a) {
        is >> x;
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    if (c >= a and c >= b or a == b) {
        cout << "None" << endl;
    } else if (a >= c and a > b) {
        cout << "LeftToRight" << endl;
    } else if (b >= c and b > a) {
        cout << "RightToLeft" << endl;
    }

    return 0;
}