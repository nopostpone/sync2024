#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s, o;
    cin >> s >> o;

    vector<string> a, b;

    for (int i = 0, p = 0; i < 2 * n; i++) {
        int q = s.find(',', p);
        a.push_back(s.substr(p, q - p));
        p = q + 1;
    }

    int l = 0, r = n;
    for (auto c : o) {
        if (c == 'L') {
            b.push_back(a[l]);
            l++;
        } else {
            b.push_back(a[r]);
            r++;
        }
    }
    reverse(b.begin(), b.end());

    for (int i = 0; i < 2 * n; i += 2) {
        cout << b[i] << endl;
    }

    return 0;
}