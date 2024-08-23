// https://ac.nowcoder.com/acm/contest/85598/E
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    k1 = min(k1, 63);
    k2 = min(k2, 63);

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector p(n + 1, vector<int>(64));
    for (int i = 1; i <= n; i++) {
        for (int j = k1; j < 64; j++) {
            p[i][j] = p[i - 1][j] + ((a[i - 1] >> j) & 1);
        }
    }

    
    
    return 0;
}