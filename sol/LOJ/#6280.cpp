// https://loj.ac/p/6280
// 2024.8.6 重新写了一下，整洁一点
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

struct Info {
    ll sum = 0;
    ll add = 0;
    int act = 0;
};

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

    vector<Info> info(id.back() + 1);
    for (int i = 0; i < n; i++) {
        info[id[i]].act++;
        info[id[i]].sum += a[i];
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
            c++;
            ll ans = 0;
            if (sid == eid) {
                for (int i = l; i <= r; i++) {
                    ans = (ans + a[i] % c + info[sid].add % c) % c;
                }
            } else {
                for (int i = l; id[i] == sid; i++) {
                    ans = (ans + a[i] % c + info[sid].add % c) % c;
                }
                for (int i = r; id[i] == eid; i--) {
                    ans = (ans + a[i] % c + info[eid].add % c) % c;
                }
                for (int i = sid + 1; i != eid; i++) {
                    ans = (ans + info[i].sum % c) % c;
                }
            }
            res.push_back(ans);
        } else {
            if (sid == eid) {
                for (int i = l; i <= r; i++) {
                    a[i] += c;
                    info[sid].sum += c;
                }
            } else {
                for (int i = l; id[i] == sid; i++) {
                    a[i] += c;
                    info[sid].sum += c;
                }
                for (int i = r; id[i] == eid; i--) {
                    a[i] += c;
                    info[eid].sum += c;
                }
                for (int i = sid + 1; i != eid; i++) {
                    info[i].sum += 1LL * c * info[i].act;
                    info[i].add += c;
                }
            }
        }
    }

    for (auto &i : res) {
        cout << i << endl;
    }

    return 0;
}