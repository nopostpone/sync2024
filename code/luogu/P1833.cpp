#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int Time(const string &s, const string &t) {
    int x1 = s.find(':');
    int x2 = t.find(':');
    int H = stoi(t.substr(0, x2)) - stoi(s.substr(0, x1)); 
    int M = stoi(t.substr(x2 + 1, 2)) - stoi(s.substr(x1 + 1, 2));
    return H * 60 + M;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int time = Time(s, t);

    int n;
    cin >> n;

    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    vector<array<int, 2>> b;
    for (auto [t, c, p] : a) {
        if (p == 0) {
            for (int i = 1; t * i < 1000; i *= 2) {
                b.push_back({i * t, i * c});
            }
        } else {
            for (int i = 1; p - i > 0; i *= 2) {
                b.push_back({i * t, i * c});
                p -= i;
            }
            if (p != 0)
                b.push_back({t * p, c * p});
        }
    }

    vector<int> dp(time + 1);
    for (auto [t, c] : b) {
        for (int i = time; i >= t; i--) {
            dp[i] = max(dp[i], dp[i - t] + c);
        }
    }
    
    cout << dp.back() << endl;

    return 0;
}