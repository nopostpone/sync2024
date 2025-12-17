#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

vector<int> query(const vector<int> &a) {
    cout << "? " << a.size() << " ";
    for (auto i : a) {
        cout << i + 1 << " ";
    }
    cout << endl;

    int n;
    cin >> n;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    return move(ans);
}

void solve() {
    int n;
    cin >> n;

    auto answer = [&](const vector<int> &a) {
        cout << "! ";
        for (int i = 0; i < n + 1; i++) {
            cout << a[i] + 1 << " ";   
        }
        cout << endl;
    };

    vector<int> p(n * n + 1);
    ranges::iota(p, 0);

    auto a0 = query(p);
    int m = a0.size();
    if (a0.size() >= n + 1) {
        answer(a0);
        return;
    }

    vector<vector<int>> seq(m);
    for (int j = 0; j < m - 2; j++) {
        int k = a0[j];

        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
