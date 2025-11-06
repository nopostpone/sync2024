#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n;
    cin >> n;

    if (n <= 10) {
        cout << n - 1 << endl;
        return 0;
    }

    vector<ll> a(100);
    int m;

    a[1] = 10;
    for (int i = 2; i < 100; i++) {
        int x = i & 1 ? i / 2 + 1 : i / 2;
        a[i] = 1ll * std::pow(10, x - 1) * 9;
        if (a[i] > 1e18) {
            m = i + 1;
            break;
        }
    }
    for (int i = 1; i < m; i++) {
        a[i] = a[i - 1] + a[i];
        if (a[i] > 1e18) {
            m = i + 1;
            break;
        }
    }

    for (int i = 2; i < m; i++) {
        if (a[i - 1] < n and n <= a[i]) {
            ll d = n - a[i - 1];
            if (d == 0) {
                while (i--)
                    cout << 9;
                break;
            }
            d--;
            vector<int> c;
            while (d) {
                c.push_back(d % 10);
                d /= 10;
            }
            int x = i % 2 ? i / 2 + 1 : i / 2;
            while (c.size() < x) {
                c.push_back(0);
            }
            c.back()++;
            for (int j = c.size() - 1; ~j; j--) {
                cout << c[j];
            }
            for (int j = i & 1; j < c.size(); j++) {
                cout << c[j];
            }
            break;
        }
    }

    return 0;
}