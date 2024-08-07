// https://loj.ac/p/6279

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int len = sqrt(n);

    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        id[i] = i / len;
    }

    vector<ll> tag(id.back() + 1);
    vector b(tag.size(), vector<ll>());

    auto cmp = [&](int x, int y) { return a[x] < a[y]; };

    for (int i = 0; i < n; i++) {
        b[id[i]].push_back(i);
    }
    for (auto &x : b) {
        sort(x.begin(), x.end(), cmp);
    }

    vector<ll> res;
    for (int zz = 0; zz < n; zz++) {
        bool opt;
        int l, r;
        ll c;
        cin >> opt >> l >> r >> c;
        l--, r--;
        int sid = id[l], eid = id[r];

        if (opt) {
            ll tmp = -1e9;
            bool ok = false;
            if (sid == eid) {
                for (int i = l; i <= r; i++) {
                    if (a[i] + tag[sid] < c) {
                        tmp = max(tmp, a[i] + tag[sid]);
                        ok = true;
                    }
                }
            } else {
                for (int i = l; id[i] == sid; i++) {
                    if (a[i] + tag[sid] < c) {
                        tmp = max(tmp, a[i] + tag[sid]);
                        ok = true;
                    }
                }
                for (int i = r; id[i] == eid; i--) {
                    if (a[i] + tag[eid] < c) {
                        tmp = max(tmp, a[i] + tag[eid]);
                        ok = true;
                    }
                }
                for (int i = sid + 1; i < eid; i++) {
                    if (a[b[i].front()] >= c - tag[i]) {
                        continue;
                    }
                    a[n] = c - tag[i];
                    auto loc = lower_bound(b[i].begin(), b[i].end(), n, cmp);
                    ok = true;
                    tmp = max(tmp, a[*(loc - 1)] + tag[i]);
                }
            }
            res.push_back(ok ? tmp : -1);
        } else {
            if (sid == eid) {
                for (int i = l; i <= r; i++) {
                    a[i] += c;
                }
                sort(b[sid].begin(), b[sid].end(), cmp);
            } else {
                for (int i = l; id[i] == sid; i++) {
                    a[i] += c;
                }
                sort(b[sid].begin(), b[sid].end(), cmp);
                for (int i = r; id[i] == eid; i--) {
                    a[i] += c;
                }
                sort(b[eid].begin(), b[eid].end(), cmp);
                for (int i = sid + 1; i < eid; i++) {
                    tag[i] += c;
                }
            }
        }
    }

    for (auto &i : res)
        cout << i << endl;

    return 0;
}