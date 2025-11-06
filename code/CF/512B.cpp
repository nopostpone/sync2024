#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<array<int, 2>> A(n);
    for (int j : {0, 1}) {
        for (int i = 0; i < n; i++) {
            cin >> A[i][j];
        }
    }

    vector<int> dp(5e4, 2e9);

    vector<int> G; // 下标 -> 数
    unordered_map<int, int> iG; // 数 -> 下标

    for (auto [l, c] : A) {
        for (int g = 0; g < (int)G.size(); g++) {
            int t = std::gcd(G[g], l);
            if (not iG.contains(t)) {
                iG[t] = (int)G.size();
                G.push_back(t);
            }
            dp[iG[t]] = min(dp[iG[t]], dp[g] + c);
        }
        if (not iG.contains(l)) {
            iG[l] = (int)G.size();
            G.push_back(l);
        }
        dp[iG[l]] = min(dp[iG[l]], c);
    }

    if (iG.contains(1)) {
        cout << dp[iG[1]] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

