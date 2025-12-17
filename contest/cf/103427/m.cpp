#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = s.size();

    vector<int> f(n + 1, -1);
    for (int i = 1, j = 0, k = 0; i <= n; i++) {
        if (f[i] == -1) {
            f[i] = j;
        }

        if (i == n) {
            break;
        }
        if (s[i] == s[k]) {
            k++;
        } else if (s[i] < s[k]) {
            k = j;
        } else {
            i = j = k = i - (i - j) % (i - k);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << f[i] + 1 << " " << i << "\n";
    }
    
}