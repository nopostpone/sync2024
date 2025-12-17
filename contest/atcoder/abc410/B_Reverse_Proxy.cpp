#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        int ans;
        if (x == 0) {
            int mn = 1e9;
            int p = 1e9;
            for (int j = n - 1; j >= 0; j--) {
                if (a[j] <= mn) {
                    p = j;
                    mn = a[j];
                }
            }
            ans = p;
            a[p]++;
            
        } else {
            x--;
            a[x]++;
            ans = x;
        }
        cout << ans + 1 << " ";
    }

    return 0;
}