#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> g(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        g[p[i]] = i;
    }

    int ans = n - 1, now = 0;

    vector<int> b;
    for (int i = n - 1; i >= 0; i--) {
        b.push_back(g[i]);
        for (int j = (int)b.size() - 1; j > 0; j--) {
            if (b[j] < b[j - 1]) {
                break;
            }
            swap(b[j], b[j - 1]);
            now++;
        }
        if (now > n) {
            break;
        }
        ans = min(ans, now + i);
    }

    cout << ans << "\n";
    
    return 0;
}