// https://loj.ac/p/6281
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr ll inf = -1e18;

struct Info {
    ll sum = 0;
    ll mx = -inf;
    int act = 0;

    void reset() {
        this->sum = 0;
        this->mx = -inf;
    }
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
        info[id[i]].mx = max<ll>(info[id[i]].mx, a[i]);
    }
    vector<ll> res;

    // 同一块内的暴力更新
    auto upd = [&](int l, int r) {
        int now = id[l];
        if (info[now].mx == 1) {
            return;
        }
        for (int i = l; i <= r; i++) {
            a[i] = sqrt(a[i]);
        }

        info[now].reset();
        for (int i = len * now; i < len * (now + 1); i++) {
            info[now].mx = max<ll>(info[now].mx, a[i]);
            info[now].sum += a[i];
        }

        if (info[now].mx == 1) {
            info[now].sum = info[now].act; 
        }
    };

    // 同一块内的暴力询问
    auto que = [&](int l, int r) {
        if (info[id[l]].mx == 1) {
            return 1LL * r - l + 1;
        }
        ll ans = 0;
        for (int i = l; i <= r; i++) {
            ans += a[i];
        }
        return ans;
    };

    for (int zz = 0; zz < n; zz++) {
        bool opt;
        int l, r;
        ll c;
        cin >> opt >> l >> r >> c;
        l--, r--;
        int sid = id[l], eid = id[r];

        if (opt) {
            ll ans = 0;
            if (sid == eid) {
                // 如果在同一块内，直接暴力求和
                ans = que(l, r);
            } else {
                // 否则先对两边散块暴力求和，再遍历中间的整块
                ans += que(l, (sid + 1) * len - 1);
                ans += que(eid * len, r);
                for (int i = sid + 1; i < eid; i++) {
                    ans += info[i].sum;
                }
            }
            res.push_back(ans);
        } else {
            if (sid == eid) {
                // 如果在同一块内，暴力更新
                upd(l, r);
            } else {
                // 否则，先暴力更新两边的散块，然后对中间的整块用懒标记更新（需要重构 sum ）
                upd(l, (sid + 1) * len - 1);
                upd(eid * len, r);
                for (int i = sid + 1; i < eid; i++) {
                    if (info[i].mx == 1) 
                        continue;

                    info[i].mx = sqrt(info[i].mx);
                    if (info[i].mx == 1) {
                        info[i].sum = info[i].act; 
                        continue;
                    }

                    info[i].sum = 0;
                    for (int j = i * len; j < (i + 1) * len; j++) {
                        a[i] = sqrt(a[i]);
                        info[i].sum += a[i];
                    }
                }
            }
        }
    }

    for (auto &i : res) {
        cout << i << endl;
    }

    return 0;
}