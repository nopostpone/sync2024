#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    n += 2;
    
    string s, t;
    cin >> s >> t;
    s += "  ";
    t += "  ";

    using psi = pair<string, int>;

    queue<psi> q;
    q.push({s, 0});

    set<string> vis;
    vis.insert(s);

    int res = -1;
    while (!q.empty()) {
        auto [now, cost] = q.front();
        q.pop();
        cerr << now << endl;
        if (now == t) {
            res = cost;
            break;
        }
        
        int pos = -1;
        for (int i = 0; i < n - 1; i++) {
            if (now[i] == ' ' and now[i + 1] == ' ') {
                pos = i;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (now[i] != ' ' and now[i + 1] != ' ') {
                string nxt = now;
                nxt[pos] = nxt[i];
                nxt[pos + 1] = nxt[i + 1];
                nxt[i] = nxt[i + 1] = ' ';

                if (not vis.contains(nxt)) {
                    q.push({nxt, cost + 1});
                    vis.insert(nxt);
                }
            }
        }
    }

    cout << res << endl;
    
    return 0;
}