#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 把所有 1 拿出来，先和 0 配对，然后再队尾和队首配对

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 1ll * (1 + n) * n / 2;
    
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            q.push_back(i);
        }
    }

    for (int i = n - 1; ~i and not q.empty(); i--) {
        if (s[i] == '0' and i < q.back()) {
            ans -= q.back() + 1;
            q.pop_back();
        }
    }

    while (q.size() > 1) {
        ans -= q.back() + 1;
        q.pop_back();
        q.pop_front();
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}