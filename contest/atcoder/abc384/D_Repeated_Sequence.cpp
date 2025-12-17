#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    ll s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const ll sum = accumulate(a.begin(), a.end(), 0ll);

    s %= sum;
    bool ok = (s == 0);

    deque<int> q;
    ll now{};
    for (int i = 0; i < 2 * n and not ok; i++) {
        now += a[i % n];
        q.push_back(a[i % n]);
        while (now > s) {
            now -= q.front();
            q.pop_front();
        }
        if (now == s) {
            ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
