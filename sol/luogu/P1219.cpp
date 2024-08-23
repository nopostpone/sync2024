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
        if (find(a.begin(), a.end(), col) != a.end()) {
            return false;
        }
        if (vis1[n + ln - col]) {
            return false;
        }
        if (vis2[ln + col]) {
            return false;
        }
        return true;
    };

    auto up = [&](int ln, int col) {
        a.push_back(col);
        vis1[n + ln - col] = true;
        vis2[ln + col] = true;
    };

    auto down = [&](int ln, int col) {
        a.pop_back();
        vis1[n + ln - col] = false;
        vis2[ln + col] = false;
    };

    auto dfs = [&](auto self, int dep) -> void {
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
                up(dep, i);
                self(self, dep + 1);
                down(dep, i);
            }
        }
    };

    dfs(dfs, -1);

    cout << cnt;

    return 0;
}
