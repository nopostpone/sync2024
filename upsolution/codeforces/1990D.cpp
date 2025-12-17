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

    int res = 0;
    vector<int> tag(n, -1);
    for (int i = 0; i < n; i++) {
        if ((tag[i] == 0 and a[i] <= 2) or a[i] == 0) {
            continue;
        }
        bool ok = (tag[i] != -1 and a[i] <= 4) or a[i] <= 2;
        res++;
        if (i == n - 1 or not ok) {
            continue;
        }
        if (tag[i] == -1) {
            tag[i + 1] = 0;
        } else {
            tag[i + 1] = not tag[i];
        }
    }

    cout << res << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}