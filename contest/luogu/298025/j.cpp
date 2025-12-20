#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = accumulate(a.begin(), a.end(), i64());

    vector<int> x(m), t(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> t[i];
        t[i]--;
    }

    vector<int> nxt(m);

    vector<int> ft(n, -1);
    for (int i = m - 1; i >= 0; i--) {
        nxt[i] = ft[t[i]];
        ft[t[i]] = i;
    }

    // for (int i = 0; i < m; i++) {
    //     cerr << nxt[i] << " \n"[i == m - 1];
    // }

    priority_queue<int, vector<int>, greater<>> q;
    {
        vector<bool> vis(n);
        for (int i = 0; i < m; i++) {
            if (not vis[t[i]]) {
                q.push(i);
            }
            vis[t[i]] = true;
        }
    }

    auto ori = a;

    int lstx = 0;
    for (int i = 0; i < m; i++) {
        while (not q.empty() and q.top() < i) {
            q.pop();
        }

        auto cur = x[i] - lstx;
        while (not q.empty()) {
            int j = t[q.top()];
            if (cur < a[j]) {
                break;
            }
            q.pop();
            cur -= a[j];
            ans -= a[j];
            a[j] = 0;

        }
        if (not q.empty() and cur) {
            int j = t[q.top()];
            a[j] -= cur;
        }
        ans -= cur;
        if (ans < 0) {
            cout << x[i] + ans << "\n";
            return;
        }
        int j = t[i];
        ans += ori[j] - a[j];
        a[j] = ori[j];

        if (nxt[i] != -1) {
            q.push(nxt[i]);
        }

        lstx = x[i];
    }

    cout << x.back() + ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}