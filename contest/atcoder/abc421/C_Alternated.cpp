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

    int n;
    cin >> n;

    string s;
    cin >> s;

    auto work = [&](char x) {
        vector<int> p, q;
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == x and (i % 2)) {
                p.push_back(i);
            }
            if (s[i] != x and (i % 2 == 0)) {
                q.push_back(i);
            }
        }
        i64 res = 0;
        for (int i = 0; i < p.size(); i++) {
            res += abs(p[i] - q[i]);
        }
        return res;
    };

    i64 ans = min(work('A'), work('B'));
    cout << ans << "\n";

    return 0;
}