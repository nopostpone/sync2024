#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a;
    for (int i = 0; i < k + 1; i++) {
        int p;
        cin >> p;

        a.push_back(p);
    }

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }

        int ans;
        if (x == y) {
            ans = 1;
        } else {
            if (upper_bound(a.begin(), a.end(), x) == upper_bound(a.begin(), a.end(), y)) {
                ans = 2;
            } else {
                int l = lower_bound(a.begin(), a.end(), x) - a.begin();
                int r = upper_bound(a.begin(), a.end(), y) - a.begin();

                ans = 2 + r - l;
                if (r != k + 1 and a[r] != y + 1) {
                    ans--;
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}