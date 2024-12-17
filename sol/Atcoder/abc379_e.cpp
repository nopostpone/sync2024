#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + 1ll * (s[i] - '0') * (i + 1);
    }

    constexpr int N = 3e5;
    vector<ll> p(N);

    for (int i = 0; i < n; i++) {
        p[0] += 1ll * (s[i] - '0') * (i + 1);
    }
    for (int i = 1; i < n; i++) {
        p[i] += pre[n - i];
    }

    for (int i = 0; i < N - 2; i++) {
        vector<int> stk;
        while (p[i] >= 10) {
            stk.push_back(p[i] % 10);
            p[i] /= 10;            
        }
        if (stk.empty()) {
            continue;
        }
        p[i + stk.size()] += p[i];
        p[i] = 0;
        for (int j = stk.size() - 1; ~j; j--) {
            p[i + j] += stk[j];
        }
    }

    bool ok{};
    for (int i = N - 1; ~i; i--) {
        if (ok) {
            cout << p[i];
            continue;
        }
        if (p[i - 1] != 0) {
            ok = true;
        }
    }
    
    return 0;
}