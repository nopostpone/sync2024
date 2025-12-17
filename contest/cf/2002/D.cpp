#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    int H = log2(n + 1);
    int X = n / 2 + 1;
    int L = H - 1;

    vector<int> fa(n + 1, -1), num(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    vector<int> valid(n + 1, 1);

    auto check = [&](int u) {
        if (u * 2 > n)
            return true;
        return (num[u * 2] / 2 == num[u] and num[u * 2 + 1] / 2 == num[u]);
    };

    function<void(int)> upd = [&](int u) {
        if (!check(u)) {
            valid[u] = 0;
            return;
        }
        if (u * 2 > n) {
            return;
        }
        upd(u * 2);
        upd(u * 2 + 1);
    };


    while (q--) {
        int x, y;
        cin >> x >> y;
        swap(num[x], num[y]);
        upd(1);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (valid[i]) {
                continue;
            }
            ok = false;
            break;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cerr << fixed << setprecision(10);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}