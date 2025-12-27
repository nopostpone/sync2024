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

    int n, q;
    cin >> n >> q;

    vector<int> a(n), in(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        in[a[i]]++;
    }

    {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (not q.empty()) {
            int x = q.front();
            q.pop();
            int y = a[x];
            in[y]--;
            if (in[y] == 0) {
                q.push(y);
            }
        }
    }

    vector<pair<int, int>> bel(n, pair(-1, -1));

    vector<int> siz(n);
    vector<vector<i64>> cycleSum(n);
    for (int i = 0, cur = 0; i < n; i++) {
        if (in[i] == 0 or bel[i].first != -1) {
            continue;
        }
        vector<int> p;
        for (int j = i; bel[j].first == -1; j = a[j]) {
            bel[j] = pair(cur, p.size());
            p.push_back(j);
            siz[cur]++;
        }
        cycleSum[cur].assign(2 * siz[cur] + 1, i64());
        for (int j = 0; j < 2 * siz[cur]; j++) {
            cycleSum[cur][j + 1] = cycleSum[cur][j] + p[j % siz[cur]] + 1;
        }

        cur++;
    }

    vector<vector<i64>> chainSum(n);
    vector<int> ed(n, -1);
    for (int i = 0, cur = 0; i < n; i++) {
        if (bel[i].first != -1) {
            continue;
        }
        vector<int> p;
        for (int j = i;; j = a[j]) {
            if (bel[j].first != -1) {
                ed[cur] = j;
                break;
            }
            bel[j] = pair(cur, p.size());
            p.push_back(j);
        }

        chainSum[cur].assign(p.size() + 1, i64());
        for (int j = 0; j < p.size(); j++) {
            chainSum[cur][j + 1] = chainSum[cur][j] + p[j] + 1;
        }

        cur++;
    }

    while (q--) {
        int t, b;
        cin >> t >> b;
        b--;

        i64 ans = 0;
        
        if (in[b] == 0) {
            auto [x, y] = bel[b];
            
            int l = y;
            int r = min((int)chainSum[x].size() - 1, y + t);
            ans += chainSum[x][r] - chainSum[x][l];
            t -= r - l;
            b = ed[x];
        }
        if (t > 0) {
            auto [x, y] = bel[b];

            ans += cycleSum[x][siz[x]] * (t / siz[x]);
            t %= siz[x];
            int l = y;
            int r = y + t;
            ans += cycleSum[x][r] - cycleSum[x][l];
        }

        cout << ans << "\n";
    }

    return 0;
}