#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (count(s.begin(), s.end(), s[0]) == n) {
        cout << -1 << "\n";
        return;
    }

    vector<int> a(n);
    array<int, 3> cnt{};
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            a[i] = 0;
        } else if (s[i] == 'I') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
        cnt[a[i]]++;
    }

    vector<int> ans;
    int u = *min_element(cnt.begin(), cnt.end());
    for (int x = 0; x < 3; x++) {
        if (cnt[x] == u) {
            continue;
        }
        int p = 1;
        while ((a[p] == x) == (a[p - 1] == x)) {
            p++;
        }
        while (cnt[x] > u) {
            if (a[p] == x) {
                int y = a[p - 1];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p + 1, y);
                ans.push_back(p + 1);
                p += 2;
            } else {
                int y = a[p];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p, y);
                ans.push_back(p);
            }
            cnt[x]--;
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}