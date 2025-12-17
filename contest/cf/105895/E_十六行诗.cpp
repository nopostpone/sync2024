#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> f;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[a[i]]++;
        int cnt = 0;
        for_each(f.begin(), f.end(), [&](auto x) {
            cnt += x.second / 2;
        });
        if (cnt == 2) {
            f.clear();
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}