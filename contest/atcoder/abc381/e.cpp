#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    auto work = [&](int x) {
        int res = 1;
        for (int i = 1; x - i >= 0 and x + i < n; i++) {
            if (s[x - i] == '1' and s[x + i] == '2') {
                res += 2;
            } else {
                break;
            }
        }
        return res;
    };

    vector<int> a;
    unordered_map<int, int> f;
    for (int i = 0; i < n; i++) {
        if (s[i] == '/') {
            a.push_back(i);
            f[i] = work(i);
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        int ans = 0;
        auto L = lower_bound(a.begin(), a.end(), x);
        auto R = lower_bound(a.begin(), a.end(), y);
    }

    return 0;
}