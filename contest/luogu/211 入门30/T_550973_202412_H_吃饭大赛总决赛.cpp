#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    string tname;
    string mname[3];
    int gid;
    int r;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, t, k;
    cin >> n >> m >> t >> k;

    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].tname;
        for (int j = 0; j < 3; j++) {
            cin >> a[i].mname[j];
        }
        cin >> a[i].gid >> a[i].r;
        a[i].gid--, a[i].r--;
    }

    vector games(m, vector<int>(t, -1));
    for (int i = 0; i < n; i++) {
        games[a[i].gid][a[i].r] = i;
    }

    vector<int> res;
    set<string> ecf;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < m; j++) {
            int now = games[j][i];
            if (now == -1) {
                continue;
            }
            bool ok = true;
            for (auto name : a[now].mname) {
                if (ecf.contains(name)) {
                    ok = false;
                }
            }
            if (ok and res.size() < k) {
                res.push_back(now);
                for (auto name : a[now].mname) {
                    ecf.insert(name);
                }
            }
        }
    }

    cout << res.size() << "\n";
    for (auto i : res) {
        cout << a[i].tname;
        for (auto name : a[i].mname) {
            cout << " " << name;
        }
        cout << "\n";
    }

    return 0;
}