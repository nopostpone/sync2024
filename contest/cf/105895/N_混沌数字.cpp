#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int j = 20; j < m; j += 42) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += s[i][j] == '1';
        }
        cout << (cnt >= (double)n * 0.7);
    }
    cout << endl;

    return 0;
}