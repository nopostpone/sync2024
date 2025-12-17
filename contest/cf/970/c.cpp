#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr int N = 5e5;
vector<ll> A(N + 1);

constexpr void pre() {
    iota(A.begin(), A.end(), 0);
    for (int i = 1; i <= N; i++) {
        A[i] += A[i - 1];
    }
}

int j = 0;

void solve() {
    int l, r;
    l = 1 + j;
    r = 1000000000 - (j & 1);
    j++;

    int n = r - l + 1;
    for (int i = 1; i <= N; i++) {
        if (n <= A[i]) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    pre();

    while (T--) {
        solve();
    }

    return 0;
}