#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;

int n;
int a[N];
ll m;
ll tp;
ll mx = 0;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> tmp;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n and a[i] <= m;) {
        int l = i;
        int r = upper_bound(a + i, a + n + 1, a[i]) - a;
        tmp.push_back({r - l, a[i]});
        i = r;
    }
    mx = 0;
    // for (auto &&[i, j] : tmp) {
    //     cerr << i << ' ' << j << endl;
    // }
    // cerr << endl;
    // return;
    for (int i = 0; i < tmp.size(); i++) {
        tp = 0;
        int count = tmp[i].first;
        int val = tmp[i].second;
        tp = 1LL * count * val;
        while (tp > m) {
            tp -= val;
            count--;
        }
        if (i != tmp.size() - 1) {
            if (tmp[i + 1].second - val == 1) {
                ll dif = m - tp;
                int x = dif / tmp[i + 1].second;
                if (x >= tmp[i + 1].first) {
                    tp += 1LL * tmp[i + 1].first * tmp[i + 1].second;
                } else {
                    tp += 1LL * x * tmp[i + 1].second;
                    dif = m - tp;
                    int sheng = min(tmp[i + 1].first - x, count);
                    if (dif <= sheng) {
                        tp += dif;
                    } else {
                        tp += sheng;
                    }
                }
            }
        }
        mx = max(tp, mx);
        if (mx == m) {
            break;
        }
    }
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