// https://ac.nowcoder.com/acm/contest/85598/E
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    k1 = min(k1, 63);
    k2 = min(k2, 63);

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    auto work = [&](int x) {
        ll ans = 0, cnt = 1;
        for (int i = 1; i < n; i++) {
            bool ok = true;
            for (int j = x; j < 64; j++) {
                bool u = a[i] >> j & 1;
                bool v = a[i - 1] >> j & 1;
                if (u != v) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cnt++;
            } else {
                ans += cnt * (cnt + 1) / 2;
                cnt = 1;
            }
        }
        ans += cnt * (cnt + 1) / 2;
        return ans;
    };

    cout << work(k2) - work(k1) << endl;
    
    return 0;
}