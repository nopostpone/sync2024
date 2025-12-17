#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;


    set<char> v;
    for (auto c : s) {
        v.insert(c);
    }
    
    string t = s;
    reverse(t.begin(), t.end());
    if (s < t) {
        cout << "YES\n";
    } else if (k != 0 and v.size() > 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}