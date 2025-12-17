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

    int l, e;
    cin >> l >> e;

    if (l >= 8 or (l >= 6 and e == 1)) {
        cout << 3 << endl;
    } else if (l >= 3) {
        cout << 6 << endl;
    } else {
        cout << "Impossible";
    }


    return 0;
}