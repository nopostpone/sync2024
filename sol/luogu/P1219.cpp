#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<bool> vis1(2 * n), vis2(2 * n);
    int cnt = 0;

    vector<int> a;

    auto check = [&](int ln, int col) {
        return find(a.begin(), a.end(), col) == a.end() and !vis1[n + ln - col] and !vis2[ln + col];
    };

    auto dfs = [&](auto &&self, int dep) -> void {
        if (dep == n - 1) {
            if (cnt++ < 3) {
                for (int i = 0; i < n; i++) {
                    cout << a[i] + 1 << " \n"[i == n - 1];
                }
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(dep, i)) {
                a.push_back(i);
                vis1[n + dep - i] = true;
                vis2[dep + i] = true;

                self(self, dep + 1);

                a.pop_back();
                vis1[n + dep - i] = false;
                vis2[dep + i] = false;
            }
        }
    };

    dfs(dfs, -1);

    cout << cnt;

    return 0;
}
