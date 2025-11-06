#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    ll k;
    cin >> n >> k;

    vector<int> x(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector f(n, vector<int>(64));
    for (int i = 0; i < n; i++) {
        f[i][0] = x[i] - 1;
    }

    for (int j = 1; j < 64; j++) {
        for (int i = 0; i < n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }

    vector<int> res(n);
    iota(res.begin(), res.end(), 0);

    int t = 0;
    while (k) {
        if (k & 1) {
            for (int i = 0; i < n; i++) {
                res[i] = f[res[i]][t];
            }
        }
        t++;
        k /= 2;
    }

    for (auto i : res) {
        cout << a[i] << " ";
    }

    return 0;
}