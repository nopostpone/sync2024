#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, o;
    cin >> n >> o;

    ll ans{};

    if (o == 1) {
        vector<int> fa(n, -1), out(n);
        for (int i = 0; i < n - 1; i++) {
            cin >> fa[i];
            fa[i]--;
            out[fa[i]]++;
        }

        vector<int> p(n - 2);
        for (int i = 0, j = 0; i < n - 2; i++, j++) {
            while (out[j]) {
                j++;
            }
            p[i] = fa[j];
            while (i < n - 2 and (--out[p[i]] == 0) and p[i] < j) {
                p[i + 1] = fa[p[i]];
                i++;
            }
        }
        for (int i = 0; i < n - 2; i++) {
            ans ^= 1ll * (i + 1) * (p[i] + 1);
        }
    } else {
        vector<int> p(n), out(n);
        for (int i = 0; i < n - 2; i++) {
            cin >> p[i];
            p[i]--;
            out[p[i]]++;
        }
        p[n - 2] = n - 1;

        vector<int> fa(n);
        for (int i = 0, j = 0; i < n - 1; i++, j++) {
            while (out[j]) {
                j++;
            }
            fa[j] = p[i];
            while (i < n - 1 and --out[p[i]] == 0 and p[i] < j) {
                fa[p[i]] = p[i + 1];
                i++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            ans ^= 1ll * (i + 1) * (fa[i] + 1);
        }
    }

    cout << ans << "\n";

    return 0;
}
