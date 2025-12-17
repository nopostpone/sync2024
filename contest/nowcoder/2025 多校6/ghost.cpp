#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int P = 998244353;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = (i64)a * a % P) {
        if (b & 1) {
            res = (i64)res * a % P;
        }
    }
    return res;
}

void work(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    map<int, int> f;
    i64 ans = 0;
    do {
        stack<int> stk;
        for (auto x : p) {
            while (not stk.empty() and stk.top() > x) {
                stk.pop();
            }
            stk.push(x);
        }
        f[stk.size()]++;
    } while (next_permutation(p.begin(), p.end()));

    for (auto [x, y] : f) {
        cerr << x << " " << y << endl;
        ans += (i64)y * x * x * x % P;
    }
    cerr << ans << "\n";
}

constexpr int N = 5e5;
int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 7; i++) {
        work(i);
    }
    cout << (15918. + 12) / 9 << endl;

    // cout << (i64)n * n % P * n % P << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}