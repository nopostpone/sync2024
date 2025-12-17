#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string A;
    cin >> A;

    const int n = A.size();
    if (n % 2) {
        cout << string(n - 1, '9') << "\n";
        return;
    }

    bool ok = true;
    for (int i = 0; i < n / 2; i++) {
        if (A[i] != A[n - i - 1]) {
            ok = false;
        }
    }
    if (ok) {
        cout << A << "\n";
        return;
    }

    vector<int> stk;
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = (i == 0); j < A[i] - '0'; j++) {
            bool flag;
            if (not stk.empty() and stk.back() == j) {
                stk.pop_back();
                flag = true;
            } else {
                stk.push_back(j);
                flag = false;
            }

            if (n - i - 1 >= stk.size() and (stk.size() + n - i - 1) % 2 == 0) {
                x = i;
                y = j;
            }

            if (flag) {
                stk.push_back(j);
            } else {
                stk.pop_back();
            }
        }

        if (not stk.empty() and stk.back() == A[i] - '0') {
            stk.pop_back();
        } else {
            stk.push_back(A[i] - '0');
        }
    }

    if (x == -1) {
        cout << string((n - 2) / 2 * 2, '9') << "\n";
        return;
    }

    stk.clear();
    for (int i = 0; i <= x; i++) {
        int t = (i == x ? y : A[i] - '0');
        cout << t;

        if (not stk.empty() and stk.back() == t) {
            stk.pop_back();
        } else {
            stk.push_back(t);
        }

    }

    for (int i = x + 1; i < n - stk.size(); i++) {
        cout << 9;
    }
    while (not stk.empty()) {
        cout << stk.back();
        stk.pop_back();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}


/*
4
20250525
11451419198100
1001
1000

20244202
11451418814154
1001
99

*/