#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 1e6;

    



    vector<int> a;

    int t;
    for (cin >> t; t--;) {
        i64 n;
        cin >> n;
        assert(n >= a.back());
        cout << *prev(upper_bound(a.begin(), a.end(), n)) << "\n";
    }

    return 0;
}