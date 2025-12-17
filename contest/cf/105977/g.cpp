#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            b[i] = a[i] - a[i - 1];
        }
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + b[i];
    }

    int k;
    cin >> k;

    while (m--) {
        int s, t;
        cin >> s >> t;

        cout << k + pre[t] - pre[s] << "\n";
    }
    
    return 0;
}

/*
6 2
3 2 4 5 3 6
2
2 4
3 6
*/