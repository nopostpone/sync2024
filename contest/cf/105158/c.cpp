#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> l(n, n);
    for (int i = n - 1; i >= 0; i--) {
        l[a[i]] = i;
    }
    vector<int> r(n, -1);
    for (int i = 0; i < n; i++) {
        r[a[i]] = i;
    }

    vector<int> d(n);

    int cnt = 0;
    for (int x = 0; x < n; x++) {
        if (r[x] != -1) {
            cnt++;
            d[l[x]]++;
            d[r[x]]--;
        }
    }

    int lst = 0;
    for (int i = 0; i < n; i++) {
        if (i) {
            d[i] += d[i - 1];
        }
        if (d[i] == 0) {
            sort(a.begin() + lst, a.begin() + i + 1, greater());
            lst = i + 1;
        }
    }

    vector<int> lis;
    for (auto x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << cnt - lis.size() << "\n";

}

/*
10
1 10 2 6 10 8 9 4 4 5
*/