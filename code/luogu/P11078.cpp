#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr char rev(char x) {
    if (x == 'U') {
        return 'D';
    } else if (x == 'D') {
        return 'U';
    } else if (x == 'L') {
        return 'R';
    } else if (x == 'R') {
        return 'L';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, q, k;
    cin >> n >> m >> q >> k;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<tuple<char, int, int>> opt(q);
    for (auto &&[c, a, b] : opt) {
        cin >> c >> a >> b;
    }

    vector tag(k, vector<bool>(q / k + 1));
    vector<bool> isrev(k);
    int cur = 0;
    int x = 0, y = 0;

    for (auto [c, a, b] : opt) {
        int t = cur % k;
        int now = cur / k;
        if (tag[t][now]) {
            isrev[t] = not isrev[t];
        }

        if (isrev[t]) {
            c = rev(c);
        }
        if (c == 'U') {
            x = max(0, x - a);
        } else if (c == 'D') {
            x = min(n - 1, x + a);
        } else if (c == 'L') {
            y = max(0, y - a);
        } else if (c == 'R') {
            y = min(m - 1, y + a);
        }

        if (s[x][y] == 'X') {
            tag[t][now + 1] = not tag[t][now + 1];
            tag[t][now + b + 1] = not tag[t][now + b + 1];
        }
        cur++;
    }

    cout << x + 1 << " " << y + 1 << endl;

    return 0;
}