#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, l, r;
    cin >> n >> l >> r;

    const int len = r - l + 1;
    n++;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, -inf);
    dp[0] = a[0];

    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (q.front() == i - len) {
            q.pop_front();
        }
        while (not q.empty() and dp[q.back()] <= dp[i]) {
            q.pop_back();
        }
        q.push_back(i);

        if (i + l < n) {
            dp[i + l] = a[i + l] + dp[q.front()];
        }
        if (i + r > n) {
            ans.push_back(dp[i]);
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << "\n";

    return 0;
}