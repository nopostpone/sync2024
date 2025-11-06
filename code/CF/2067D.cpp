#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }

    vector<int> t(n, -1);
    for (int i = 0; i < n; i++) {
        t[x[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (t[i] == -1) {

            int a = ask(i, (i + 1) % n);
            if (a == 0) {
                cout << "! A" << endl;
            } else {
                cout << "! B" << endl;
            }

            return;
        }
    }

    int u = t[0];
    int v = t[n - 1];

    int a = ask(u, v);
    int b = ask(v, u);

    if (a != b) {
        cout << "! A" << endl;
    } else {
        if (a + b <= n) {
            cout << "! A" << endl;
        } else {
            cout << "! B" << endl;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}