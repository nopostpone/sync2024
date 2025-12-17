#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto work = [&](int x) -> int {
        int res = 0;
        int st = x - 2;
        unordered_map<int, int> f;

        for (int i = x; i < n; i += 2) {
            if (a[i] != a[i - 1]) {
                res = max(res, i - st - 2);
                f.clear();
                st = i;
                continue;
            }
            if (f.contains(a[i]) and f[a[i]] > st) {
                res = max(res, i - st - 2);
                st = f[a[i]];
            }
            f[a[i]] = i;
            if (i + 2 >= n) {
                res = max(res, i - st);
            }
        }
        return res;
    };

    cout << max(work(1), work(2)) << endl;

    return 0;
}