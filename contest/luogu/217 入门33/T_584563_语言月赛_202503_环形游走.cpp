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

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    cin >> a;

    for (auto &x : a) {
        x %= n;
    }

    int k = 0;
    for (int i = 0; i < m; i++) {
        k -= a[k];
        while (k < 0) {
            k += n;
        }
        k %= n;
    }
    cout << k + 1 << endl;

    return 0;
}