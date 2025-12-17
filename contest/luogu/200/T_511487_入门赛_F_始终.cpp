#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;

    const int n = s.size();

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            string t = s.substr(i, j);
            res += (t.front() == t.back());
        }
    }
    cout << res << endl;

    return 0;
}