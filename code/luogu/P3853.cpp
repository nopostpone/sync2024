#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, N, K;
    cin >> L >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    auto check = [&](int x) {
        int cnt = 0;
        for (int i = 1; i < N; i++) {
            cnt += (a[i] - a[i - 1] - 1) / x;
        }
        return cnt <= K;
    };

    int lo = 1, hi = L + 1;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (check(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << lo << endl;

    return 0;
}
