#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    string ans;
    auto work = [&](string t) {
        array<bool, 20> occ {};
        array<int, 20> f;
        f.fill(-1);

        for (int i = (int)t.size() - 1, cur = 0; i >= 0; i--) {
            int x = t[i] - 'a';
            if (not occ[x]) {
                occ[x] = true;
                f[x] = cur++;
            }
        }

        for (auto &c : t) {
            c = 'a' + f[c - 'a'];
        }

        ans = max(ans, t);
    };

    for (int i = 1; i <= n; i++) {
        work(s.substr(0, i));
    }

    cout << ans << "\n";
}