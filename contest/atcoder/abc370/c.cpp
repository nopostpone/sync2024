#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string s, t;
    cin >> s >> t;

    const int n = s.size();

    vector<string> res;
    for (int i = 0; i < n; i++) {
        if (s[i] > t[i]) {
            s[i] = t[i];
            res.push_back(s);
        }
    }
    for (int i = n - 1; ~i; i--) {
        if (s[i] < t[i]) {
            s[i] = t[i];
            res.push_back(s);
        }
    }
    cout << res.size() << endl;

    for (auto i : res)
        cout << i << endl;
    
    return 0;
}