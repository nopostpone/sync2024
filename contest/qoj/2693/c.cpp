#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
    }
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }

        vector<int> cnt(m + 1);
        cnt[0] = n;
        for (int i = 0; i < n; i++) {
            for (int x = 0; x < m; x++) {
                if (a[i] == b[x] and cnt[x] > 0) {
                    cnt[x]--;
                    cnt[x + 1]++;
                }
            }
        }

        cout << cnt[m] << "\n";
    }
}

/*
4
4 2 1 3
3
8 4 2 1 3 4 2 3 1
9 1 4 2 4 1 2 1 3 3
12 1 1 2 3 4 2 1 1 2 1 3 3

1
1
1
10 1 2 1 2 1 2 1 2 1 2
*/