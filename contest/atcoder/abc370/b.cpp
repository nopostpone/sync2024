#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector mp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> mp[i][j];
            mp[i][j]--;
        }
    }

    int now = 0;
    for (int i = 0; i < n; i++) {
        if (now >= i) {
            now = mp[now][i];
        } else {
            now = mp[i][now];
        }
    }
    cout << now + 1;
    
    return 0;
}