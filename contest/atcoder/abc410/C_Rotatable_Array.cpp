#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    int d = 0;
    while (q--) {
        int o;
        cin >> o;

        if (o == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            p = (p + d) % n;
            a[p] = x;
        } else if (o == 2) {
            int p;
            cin >> p;
            p--;
            p = (p + d) % n;
            cout << a[p] << "\n";
        } else {
            int k;
            cin >> k;
            k %= n;
            d = (d + k) % n;
        }
    }

    return 0;
}