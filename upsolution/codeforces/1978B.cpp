#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dif;
    int tmpmx = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] > tmpmx) {
            tmpmx = a[i];
            continue;
        }
        dif.push_back(tmpmx - a[i]);
    }
    if (dif.empty()) {
        cout << 0 << endl;
        return;
    }
    ll cnt = 0;
    ll cost = 0;
    sort(dif.begin(), dif.end(), [&](int a, int b){return a > b;});
    while(!dif.empty()) {
        dif.back() -= cnt;
        if (dif.back() == 0) {
            dif.pop_back();
            continue;
        }
        cnt += 1LL * dif.back();
        cost += 1LL * dif.back() * (dif.size() + 1);
        dif.pop_back();
    }
    cout << cost << endl;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}