#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector s(n, string(m, '.'));

    int x = n / 2;

    for (int i = 0; i < (k + 1) / 2; i++) {
        for (int j = 0; j < m - i; j++) {
            s[x + i][j] = '#';
            s[x - i][j] = '#';
        }
    }
    int cur{1};
    for (int j = m - 1; ~j; j--) {
        for (int i = 0; i < cur; i++) {
            // cerr << x + i << " " << j << endl;
            if (x + cur > n) {
                cur = -10000;
                break;
            }
            s[x + i][j] = s[x - i][j] = '#';
        }
        cur++;
        // cerr << j << " " << cur << endl;
        if (cur <= 0) {
            break;
        }
    }

    for (auto str : s) {
        cout << str << "\n";
    }

    return 0;
}