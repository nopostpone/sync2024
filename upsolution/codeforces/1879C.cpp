#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll P = 998244353;

void solve() {
    string s;
    cin >> s;
    s.push_back('2');

    const int n = s.size();

    char now{s[0]};
    int cnt{1};

    vector<int> dif;
    for (int i = 1; i < n; i++) {
        if (s[i] != now) {
            if (cnt > 1) {
                dif.push_back(cnt - 1);
            }
            cnt = 1;
            now = s[i];
        } else {
            cnt++;
        }
    }

    ll ans = 0;
    for (auto i : dif) {
        ans += i;
    }
    cout << ans << " ";

    for (int i = ans - 1; i > 0; i--) {
        ans = (ans * i) % P;
    }
    if (ans == 0) {
        ans = 1;
    }
    for (int i : dif) {
        ans *= (i + 1);
        ans %= P;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}
