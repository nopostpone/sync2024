#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << a.front() << endl;
        return;
    }
    for (int cnt : {0, 1}) {
        for (auto i : a)
            sum += i;
        set<int> st;
        st.insert(a[0]);
        b[0] = 0;
        for (int i = 1; i < n; i++) {
            if (st.count(a[i])) {
                b[i] = max(b[i - 1], a[i]);
            } else {
                st.insert(a[i]);
                b[i] = b[i - 1];
            }
        }
        a = b;
        if (!cnt)
            b.clear();
    }
    for (int i = 0; i < n; i++) {
        sum += 1LL * (n - i) * b[i];
    }
    cout << sum << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}