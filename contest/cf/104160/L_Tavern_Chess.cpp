#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int atk[2][7]{};

    for (int i = 0; i < n; i++) {
        cin >> atk[0][i];
    }
    for (int i = 0; i < m; i++) {
        cin >> atk[1][i];
    }

    struct Info {
        pair<int, int> a[7];
        pair<int, int> b[7];
        double p;
        bool who;
    };

    double win = 0, lose = 0, draw = 0;

    auto gameEnd = [&](const Info &cur) {
        bool adie = true;
        bool bdie = true;
        for (int i = 0; i < n; i++) {
            if (cur.a[i].first > 0) {
                adie = false;
            }
        }
        for (int i = 0; i < m; i++) {
            if (cur.b[i].first > 0) {
                bdie = false;
            }
        }

        if (adie and bdie) {
            draw += cur.p;
        } else if (adie) {
            lose += cur.p;
        } else if (bdie) {
            win += cur.p;
        } else {
            return false;
        }
        return true;
    };

    auto dfs = [&](this auto &&self, Info cur) -> void {
        if (gameEnd(cur)) {
            return;
        }

        auto &attack = cur.who ? cur.a : cur.b;
        auto &defense = cur.who ? cur.b : cur.a;

        int x = -1;
        for (int i = 0; i < 7; i++) {
            if (attack[i].first <= 0) {
                continue;
            }
            if (x == -1 or attack[i].second < attack[x].second) {
                x = i;
            }
        }
        attack[x].second++;

        vector<int> choose;
        for (int i = 0; i < 7; i++) {
            if (defense[i].first > 0) {
                choose.push_back(i);
            }
        }

        cur.who ^= 1;

        cur.p /= choose.size();
        for (auto y : choose) {
            attack[x].first -= atk[!cur.who][y];
            defense[y].first -= atk[cur.who][x];
            self(cur);
            attack[x].first += atk[!cur.who][y];
            defense[y].first += atk[cur.who][x];
        }
    };

    Info init;
    for (int i = 0; i < n; i++) {
        init.a[i] = {atk[0][i], 0};
    }
    for (int i = 0; i < m; i++) {
        init.b[i] = {atk[1][i], 0};
    }
    if (n == m) {
        init.p = 0.5;
        Info init1 = init;
        init1.who = true;
        Info init2 = init;
        init2.who = false;

        dfs(init1);
        dfs(init2);

    } else {
        init.p = 1;
        init.who = n > m;
        dfs(init);
    }

    cout << fixed << setprecision(15);
    cout << win << " " << lose << " " << draw << "\n";

    return 0;
}