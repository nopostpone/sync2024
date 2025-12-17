#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> adj(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                adj[i].push_back(j);
                in[j]++;
            }
        }
    }

    // vector<int> f(n, 1);
    // queue<int> q;
    // for (int i = 0; i < n; i++) {
    //     if (in[i] == 0) {
    //         f[i] = inf;
    //         q.push(i);
    //     }
    // }

    // while (not q.empty()) {
    //     int x = q.front();
    //     q.pop();

    //     for (auto y : adj[x]) {
    //         if (f[y] > f[x]) {
    //             cout << -1 << "\n";
    //             return 0;
    //         }
    //         in[y]--;
    //         f[y] = f[x] - 1;

    //         if (in[y] == 0) {
    //             q.push(y);
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << 1 << " " << f[i] << "\n";
    // }

    return 0;
}