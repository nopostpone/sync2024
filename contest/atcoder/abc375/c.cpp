#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<string> t(s);
    auto upd1 = [&](int i, int j) {
        t[i][j] = s[n - j - 1][i];
    };
    auto upd2 = [&](int i, int j) {
        t[i][j] = s[n - i - 1][n - j - 1];
    };
    auto upd3 = [&](int i, int j) {
        t[n - j - 1][i] = s[i][j];
    };

    auto upd = [&](int i, int j, int now) {
        if (now == 1) {
            upd1(i, j);
        } else if (now == 2) {
            upd2(i, j);
        } else if (now == 3) {
            upd3(i, j);
        }
    };

    for (int i = 0, now = 1; i < n / 2; i++, now = (now + 1) % 4) {
        for (int j = i; j < n - i; j++) {
            // cerr << i << " " << j << " " << now << endl;
            upd(i, j, now);
            upd(j, n - i - 1, now);
            upd(n - i - 1, j, now);
            upd(j, i, now);
        }
        // break;
    }
    for (int i = 0; i < n; i++) {
        cout << t[i] << "\n";
    }

    return 0;
}