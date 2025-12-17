#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 1;
    auto work = [&](int x) {
        int res = 1;
        for (int i = 1; x - i >= 0 and x + i < n; i++) {
            if (s[x - i] == '1' and s[x + i] == '2') {
                res += 2;
            } else {
                break;
            }
        }
        ans = max(ans, res);
    };

    for (int i = 0; i < n; i++) {
        if (s[i] == '/') {
            work(i);
        }
    }
    cout << ans << endl;

    return 0;
}