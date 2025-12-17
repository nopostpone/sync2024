#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += s.substr(i, 5) == "edgnb";
    }
    cout << ans << "\n";
}