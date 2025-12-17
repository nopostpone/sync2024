#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;

int n;
struct flw {
    int val, cnt;
    bool operator<(const flw &o) {
        return val < o.val;
    }
}a[N];
ll m;
ll tp;
ll mx = 0;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].cnt;
    }
    sort(a + 1, a + 1 + n);

    mx = 0;
    for (int i = 1; i <= n; i++) {
        int count = a[i].cnt;
        int val = a[i].val;
        tp = 1LL * count * val;
        while (tp > m) {
            tp -= val;
            count--;
        }
        if (i != n) {
            if (a[i + 1].val - val == 1) {
                ll dif = m - tp;
                int x = dif / a[i + 1].val;
                if (x >= a[i + 1].cnt) {
                    tp += 1LL * a[i + 1].cnt * a[i + 1].val;
                } else {
                    tp += 1LL * x * a[i + 1].val;
                    dif = m - tp;
                    int sheng = min(a[i + 1].cnt - x, count);
                    if (dif <= sheng) {
                        tp += dif;
                    } else {
                        tp += sheng;
                    }
                }
            }
        }
        // cerr << tp << endl;
        mx = max(tp, mx);

        if (mx == m) {
            break;
        }
    }
    // cerr << endl;
    cout << mx << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}