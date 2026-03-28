#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

auto safeFind(const string &s, int p) {
    int q = s.find('.', p);
    if (q == -1) {
        q = s.size();
    }
    return q;
}

void solve() {
    string a, b;
    cin >> a >> b;

    int pa = 0, pb = 0;
    while (pa < a.size() and pb < b.size()) {
        int qa = safeFind(a, pa);
        int qb = safeFind(b, pb);

        int na = stoi(a.substr(pa, qa - pa));
        int nb = stoi(b.substr(pb, qb - pb));

        if (na != nb) {
            cout << (na > nb ? "A" : "B") << "\n";
            return;
        }
        pa = qa + 1;
        pb = qb + 1;
    }
    cout << "Equal\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}