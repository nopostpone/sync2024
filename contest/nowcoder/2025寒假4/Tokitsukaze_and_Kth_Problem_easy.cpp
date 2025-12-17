#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> f;
    for (int x : a) {
        f[x]++;
    }

    auto b = a;
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < b.size(); ++i) {
        for (int j = i; j < b.size(); ++j) {
            int num1 = b[i], num2 = b[j];
            long long cnt1 = f[num1], cnt2 = f[num2];
            int sum_mod = (num1 + num2) % p;
            if (num1 == num2) {
                long long total = cnt1 * (cnt1 - 1) / 2;
                if (total > 0)
                    pq.push({sum_mod, total});
            } else {
                long long total = cnt1 * cnt2;
                if (total > 0)
                    pq.push({sum_mod, total});
            }
        }
    }

    vector<int> ans;
    while (!pq.empty() && ans.size() < k) {
        auto top = pq.top();
        pq.pop();
        int mod_val = top.first;
        long long count = top.second;
        for (int i = 0; i < count && ans.size() < k; ++i) {
            ans.push_back(mod_val);
        }
    }

    ans.resize(k, -1);
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " \n"[i == k - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}