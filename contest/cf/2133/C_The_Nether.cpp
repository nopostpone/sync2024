#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int query(int x, const vector<int> &s) {
    cout << "? " << x + 1 << " " << s.size();
    for (auto y : s) {
        cout << " " << y + 1;
    }
    cout << endl;

    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    ranges::iota(p, 0);

    vector<int> seq;


    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < n; i++) {
        int t = query(i, p);
        vec[t].push_back(i);
    }
    
    int lst = -1;
    for (int t = n; t >= 0; t--) {
        for (auto x : vec[t]) {
            if (lst == -1) {
                seq.push_back(x);
                lst = x;
                break;
            } else {
                if (query(lst, {lst, x}) == 2) {
                    seq.push_back(x);
                    lst = x;
                    break;
                }
            }
        }
    }

    cout << "! " << seq.size() << " ";
    for (auto x : seq) {
        cout << x + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}