#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans += (s[i] == '.' and s[i - 1] == '#' and s[i + 1] == '#');
    }
    cout << ans << endl;
    
    return 0;
}