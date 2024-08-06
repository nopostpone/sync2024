// https://loj.ac/p/6277
// 2024.8.6 重新写了一下，整洁一点
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int len = sqrt(n);

    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        id[i] = i / len;
    }

    vector<ll> tag(id.back() + 1);
    vector<ll> res;

    for (int zz = 0; zz < n; zz++) {
        bool opt;
        int l, r;
        ll c;
        cin >> opt >> l >> r >> c;
        l--, r--;
        if (opt) {
            res.push_back(a[r] + tag[id[r]]);
        } else {
            int sid = id[l], eid = id[r];
            if (sid == eid) {
                for (int i = l; i <= r; i++) {
                    a[i] += c;
                }
            } else {
                for (int i = l; id[i] == sid; i++) {
                    a[i] += c;
                }
                for (int i = r; id[i] == eid; i--) {
                    a[i] += c;
                }
                for (int i = sid + 1; i != eid; i++) {
                    tag[i] += c;
                }
            }
        }
    }

    for (auto &i : res) {
        cout << i << endl;
    }

    return 0;
}