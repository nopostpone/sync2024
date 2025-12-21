#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool vis[410][13] {};
    int cnt[410] {};

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        int ans = 0;

        if (not vis[a][b]) {
            vis[a][b] = true;
            if (cnt[a]++ < 3 or c < 240) {
                ans = b + 1;
            }
        }
        cout << ans << "\n";
    }
}

/*
8
1 1 10
1 2 20
1 3 30
1 4 250
1 5 260
1 6 270
1 7 280
2 1 290
*/