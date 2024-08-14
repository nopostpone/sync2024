#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

struct D {
    int n;
    ll d;
    vector<int> a;
    vector<int> t;
    vector<ll> f;

    D() {}

    D(const vector<int> &_v) {
        init(_v);
        work();
    }

    void init(const vector<int> &_v) {
        n = _v.size();
        a = _v;
        t.resize(2e6 + 1);
        f.resize(2e6 + 1);
        d = 0;
    }

    void work() {
        for (auto &i : a) {
            d += i;
        }
        sort(a.begin(), a.end());
        int p = 0;
        for (int i = -1e6; i <= 1e6; i++) {
            while (a[p] == i and p < n - 1) {
                p++;
            }
            t[i + 1 * 1e6] = p;
        }
        for (int i = -1e6; i <= 1e6; i++) {
            
        }
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    D X, Y;

    vector<int> tx(n), ty(n);
    for (int i = 0; i < n; i++) {
        cin >> tx[i] >> ty[i];
    }
    X.init(tx);
    Y.init(ty);

    

    return 0;
}