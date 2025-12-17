// https://www.luogu.com.cn/problem/P5057
// 分块
// 24.9.21 upd 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    const int len = std::sqrt(n);
    vector<bool> tag(len + 1), a(n);

    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        id[i] = i / len;
    }

    while (m--) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            int y;
            cin >> y;
            y--;
            if (id[x] == id[y]) {
                for (int i = x; i <= y; i++) {
                    a[i] = not a[i];
                }
            } else {
                for (int i = x; id[i] == id[x] and i < n; i++) {
                    a[i] = not a[i];
                }
                for (int i = id[x] + 1; i < id[y]; i++) {
                    tag[i] = not tag[i];
                }
                for (int i = y; id[i] == id[y] and i; i--) {
                    a[i] = not a[i];
                }
            }

        } else {
            cout << (a[x] xor tag[id[x]]) << "\n";
        }
    }

    return 0;
}