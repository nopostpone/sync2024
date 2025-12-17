#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, t, p, k;
    cin >> n >> t >> p >> k;

    int lst{-1}, lst1{-1}, lst2{-1}, lst3{-1};

    vector<set<int>> f(t + 1);

    stack<int> stk;

    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            continue;
        }
        lst = x;
        if (f[x].empty()) {
            lst3 = x;
        }
        if (not f[x].contains(y)) {
            lst1 = x;
            stk.push(x);
        }
        f[x].insert(y);
    }

    while (not stk.empty()) {
        int x = stk.top();
        stk.pop();
        if (f[x].size() < k) {
            lst2 = x;
            break;
        }
    }

    cout << lst << " " << lst1 << " " << lst2 << " " << lst3 << endl;
    
    return 0;
}