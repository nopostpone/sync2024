#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 3;

struct A {
    double a, b;
    double w;
    int id;
    bool operator<(const A o) const {
        return w == o.w ? a < o.a : w > o.w;
    }
} a[N];

int n, m;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
        a[i].w = a[i].b / a[i].a;
    sort(a + 1, a + 1 + n);
    cout << a[1].id;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}