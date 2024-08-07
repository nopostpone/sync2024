// https://loj.ac/p/6281
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr ll inf = -1e18;

struct Info {
    ll sum = 0;
    bool skip = 0;
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
        info[id[i]].sum += a[i];
    }
    vector<ll> res;

    auto check = [&](int id) {
        for (int i = id * len; i < (id + 1) * len and i < n; i++) {
            if (a[i] > 1)
                return false;
        }
        return true;
    };

    // 同一块内的暴力更新
    auto upd = [&](int l, int r) {
        int now = id[l];
        if (info[now].skip) {
            return;
        }
        for (int i = l; i <= r; i++) {
            a[i] = sqrt(a[i]);
        }

        info[now].sum = 0;
        for (int i = len * now; i < len * (now + 1) and i < n; i++) {
            info[now].sum += a[i];
        }
        info[now].skip = check(now);
    };

    // 同一块内的暴力询问
    auto que = [&](int l, int r) {
        ll ans = 0;
        for (int i = l; i <= r; i++) {
            ans += a[i];
        }
        return ans;
    };

    for (int zz = 0; zz < n; zz++) {
        bool opt;
        int l, r, c;
        cin >> opt >> l >> r >> c;
        l--, r--;
        int sid = id[l], eid = id[r];

        if (opt) {
            ll ans = 0;
            if (sid == eid) {
                ans = que(l, r);
            } else {
                ans += que(l, (sid + 1) * len - 1);
                ans += que(eid * len, r);
                for (int i = sid + 1; i < eid; i++) {
                    ans += info[i].sum;
                }
            }
            res.push_back(ans);
        } else {
            if (sid == eid) {
                upd(l, r);
            } else {
                upd(l, (sid + 1) * len - 1);
                upd(eid * len, r);

                for (int i = sid + 1; i < eid; i++) {
                    if (info[i].skip) {
                        continue;
                    }
                    upd(i * len, (i + 1) * len - 1);
                }
            }
        }
    }

    for (auto &i : res) {
        cout << i << endl;
    }

    return 0;
}