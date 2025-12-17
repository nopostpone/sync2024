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

    int n, m;
    cin >> m >> n;

    int a = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int y = x;
        int sum = 0;
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        if (x % m != 0 and sum % m == 0) {
            cout << x << endl;
            a++;
        }
    }
    if (not a) {
        cout << "None";
    }

    return 0;
}