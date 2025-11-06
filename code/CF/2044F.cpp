#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool isprime(int n) {
    return minp[n] == n;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int n, m, q;
    cin >> n >> m >> q;
 
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
 
    vector<bool> has_a(2 * n + 1), has_b(2 * m + 1);
    for (auto i : a) {
        has_a[i + n] = true;
    }
    for (auto i : b) {
        has_b[i + m] = true;
    }
 
    ll sa = accumulate(a.begin(), a.end(), 0ll);
    ll sb = accumulate(b.begin(), b.end(), 0ll);
 
    auto work = [&](ll x, ll y) {
        ll need_a = sa - x + n;
        ll need_b = sb - y + m;
        if (0 <= need_a and need_a <= 2 * n and has_a[need_a] and
            0 <= need_b and need_b <= 2 * m and has_b[need_b]) {
            return true;
        }
        
        need_a = sa - y + n;
        need_b = sb - x + m;
        if (0 <= need_a and need_a <= 2 * n and has_a[need_a] and
            0 <= need_b and need_b <= 2 * m and has_b[need_b]) {
            return true;
        }
        return false;
    };
 
    while (q--) {
        int x;
        cin >> x;
 
        bool ok{};
        for (int i = 1; i * i <= std::abs(x) and not ok; i++) {
            if (x % i != 0) {
                continue;
            }
            ok |= work(i, x / i);
            ok |= work(-i, -x / i);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
 
    return 0;
}