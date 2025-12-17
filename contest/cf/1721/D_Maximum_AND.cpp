#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<array<int, 30>> pa(n), pb(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if (a[i] >> j & 1) {
                pa[i][j] = 1;
            }
            if (b[i] >> j & 1) {
                pb[i][j] = 1;
            }
        }
    }
    vector<array<int, 30>> prea(n + 1), preb(n + 1);
    array<int, 30> cnta{}, cntb{};
    for (int j = 0; j < 30; j++) {
        for (int i = 0; i < n; i++) {
            prea[i + 1][j] = prea[i][j] + pa[i][j];
            preb[i + 1][j] = preb[i][j] + pb[i][j];
            cnta[j] += pa[i][j];
            cntb[j] += pb[i][j];
        }
    }
    int ans = 0;

    vector<pair<vector<int>, vector<int>>> q;
    auto check = [&](int j) {
        bool ok = true;
        vector<pair<vector<int>, vector<int>>> nq;

        for (const auto &[ta, tb] : q) {
            if (ta.size() == 0) {
                continue;
            }
            vector<int> na0, na1, nb0, nb1;
            for (int i : ta) {
                (pa[i][j] ? na1 : na0).push_back(i);
            }
            for (int i : tb) {
                (pb[i][j] ? nb1 : nb0).push_back(i);
            }
            if (na0.size() != nb1.size()) {
                ok = false;
            }
            // cerr << na0.size() << " " << na1.size() << " " << nb0.size() << " " << nb1.size() << endl;
            nq.push_back(make_pair(na0, nb1));
            nq.push_back(make_pair(na1, nb0));
        }

        if (ok) {
            q = move(nq);
        }
        return ok;
    };

    {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        q.push_back(make_pair(p, p));
    }
    for (int j = 29; j >= 0; j--) {
        if (check(j)) {
            ans += (1 << j);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}