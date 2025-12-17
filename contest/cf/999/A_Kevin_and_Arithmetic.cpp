#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int odd{}, even{}, ans{};
    for (auto x : a) {
        if (x % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    if (even == 0) {
        ans = odd - 1;
    } else {
        ans = 1 + odd;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}