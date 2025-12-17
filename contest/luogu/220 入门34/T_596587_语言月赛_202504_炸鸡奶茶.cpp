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

    int f, m, n;
    cin >> f >> m >> n;

    cerr << n / 7 << endl;
    cerr << f + m << endl;

    cout << (n / 7) * (2 * f + m) << endl; 

    return 0;
}