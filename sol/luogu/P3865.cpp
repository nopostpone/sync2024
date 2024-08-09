// https://www.luogu.com.cn/problem/P3865
// ST表 模板
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int logn = log2(n);
    vector f(n, vector<int>(logn + 1));
    for (int i = 0; i < n; i++) {
        f[i][0] = a[i];
    }

    for (int j = 1; j <= logn; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    vector<int> res;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int s = log2(r - l + 1);
        res.push_back(max(f[l][s], f[r + 1 - (1 << s)][s]));
    }

    for (auto &i : res)
        cout << i << endl;
    
    return 0;
}