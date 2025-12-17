#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, f;
    cin >> n >> f;

    vector<tuple<int, int, int>> a(n);
    i64 ans = 0;

    int ed = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = tuple(l, r, i);
        ed = max(ed, r);
        ans += r - l;
    }
    ranges::sort(a);
    priority_queue<pair<int, int>> q;

    vector<int> seq;

    for (int i = 0, cur = f; cur < ed;) {
        while (i < n and get<0>(a[i]) <= cur) {
            q.emplace(get<1>(a[i]), get<2>(a[i]));
            i++;
        }
        // cerr << i << endl;
        if (cur == ed) {
            break;
        }
        if (q.empty() or (q.top()).first < cur) {
            assert(i != n);
            
            ans += get<0>(a[i]) - cur;
            cur = get<1>(a[i]);
            seq.push_back(get<2>(a[i]));
            i++;
        } else {
            // cerr << q.top().first << endl;
            cur = q.top().first;
            seq.push_back(q.top().second);
            q.pop();
        }
    }

    cout << ans << "\n";

    vector<bool> vis(n);
    for (auto i : seq) {
        cout << i + 1 << " ";
        vis[i] = true;
    }
    for (int i = n - 1; i >= 0; i--) {
        int j = get<2>(a[i]);
        if (vis[j]) {
            continue;
        }
        cout << j + 1 << " ";
    }
    cout << "\n";
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