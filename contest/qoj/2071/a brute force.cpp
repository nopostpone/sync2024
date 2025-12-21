#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> f(n, n);

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (not stk.empty() and a[stk.back()] <= a[i]) {
            f[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    auto get = [&](int l, int r) {
        vector<int> res;
        while (f[l] < r) {
            res.push_back(l - f[l]);            
            l = f[l];
        }

        return move(res);
    };

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--;
        l2--;

        cout << (get(l1, r1) == get(l2, r2) ? "Yes" : "No") << "\n";
    }
}

/*
10 6
3 1 4 1 5 9 2 6 5 3
1 3 3 5
1 5 6 10
1 1 9 9
1 9 1 9
1 3 6 8
5 8 7 10
*/