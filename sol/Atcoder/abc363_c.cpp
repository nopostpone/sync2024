#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k;
    string s;
    cin >> n >> k >> s;

    string t = {};
    set<string> res;
    bitset<11> vis(0);

    auto check = [&]() {
        for (int i = 0; i <= t.size() - k; i++) {
            string tmp = t.substr(i, k);
            reverse(tmp.begin(), tmp.end());
            if (tmp == t.substr(i, k)) {
                return false;
            }
        }
        return true;
    };

    function<void()> dfs = [&]() {
        if (t.size() == n) {
            if (check())
                res.insert(t);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            t.push_back(s[i]);
            dfs();
            vis[i] = false;
            t.pop_back();
        }
    };

    dfs();

    cout << res.size() << endl;

    return 0;
}