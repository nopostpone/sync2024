#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    string s, t;
    cin >> n >> s >> t;

    s += "..";
    t += "..";

    set<string> vis;
    vis.insert(s);
    using psi = pair<string, int>;

    queue<psi> q;
    q.push(make_pair(s, 0));

    int ans = -1;
    while (not q.empty()) {
        auto [now, time] = q.front();
        q.pop();

        if (now == t) {
            ans = time;
            break;
        }

        int pos;
        for (int i = 0; i < n + 1; i++) {
            if (now[i] == '.' and now[i + 1] == '.') {
                pos = i;
            }
        }
        for (int i = 0; i < n + 1; i++) {
            if (now[i] != '.' and now[i + 1] != '.') {
                string nxt(now);
                nxt[pos] = nxt[i];
                nxt[pos + 1] = nxt[i + 1];
                nxt[i] = '.';
                nxt[i + 1] = '.';
                if (not vis.contains(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, time + 1});
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}