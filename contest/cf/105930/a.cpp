#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct node {
    int a, b, id;

    bool operator<(const struct node &n) const {
        if (a != n.a) {
            return a > n.a;
        } else {
            return b < n.b;
        }
    }
};

struct node a[200005];
int f[200005], g[200005];
vector<int> ans[200005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
        a[i].id = i;
    }

    sort(a + 1, a + n + 1);

    int cur = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i].a != a[i - 1].a) {
            cur = i - 1;
        }
        g[i] = cur;
    }

    f[1] = 1;
    ans[1].push_back(a[1].id);
    for (int i = 2; i <= n; i++) {
        int t = f[g[i]];
        if (t < a[i].b) {
            int key = lower_bound(a + g[i] + 1, a + i, node{a[i].a, f[g[i]], 0}) - a;
            f[i] = max(f[i - 1], t + i - key + 1);
            if (f[i - 1] < t + i - key + 1) {
                ans[i] = ans[g[i]];
                for (int j = key; j <= i; j++)
                    ans[i].push_back(a[j].id);
            } else {
                ans[i] = ans[i - 1];
            }
        } else {
            f[i] = max(f[i - 1], a[i].b + 1);
            if (f[i - 1] < a[i].b + 1) {
                ans[i] = ans[g[i]];
                ans[i].push_back(a[i].id);
            } else {
                ans[i] = ans[i - 1];
            }
        }
    }

    cout << f[n] << endl;
    for (int i = 0; i < ans[n].size(); i++)
        cout << ans[n][i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
2
 6
 3 0
 4 0
 3 1
 5 3
 1 2
 3 1
 2
 1 1
 1 0
*/