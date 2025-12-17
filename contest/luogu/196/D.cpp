#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    bool oka, okb;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        oka = 0, okb = 0;
        int t;
        cin >> t;
        while (t--) {
            int x;
            cin >> x;
            if (x == a) {
                oka = 1;
            }
            if (oka and x == b) {
                okb = 1;
            }
        }
        if (oka and okb) {
            cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}