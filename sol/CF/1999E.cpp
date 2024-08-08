#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    vector<int> a(2e5 + 1), s(2e5 + 1);
    for (int i = 1; i <= 2e5; i++) {
        a[i] = a[i / 3] + 1;
        s[i] = a[i] + s[i - 1];
    }

    vector<int> res;
    while (t--) {
        int l, r;
        cin >> l >> r;
        res.push_back(s[r] - s[l - 1] + a[l]);
    }
    for (auto i : res)
        cout << i << endl;

    return 0;
}