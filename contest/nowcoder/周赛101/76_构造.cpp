#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using u8 = unsigned char;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if ((m & 1) == 0) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> p;

    array<bool, 30> need{};
    for (int i = 0; i < 30; i++) {
        if (m >> i & 1) {
            need[i] = 1;
        }
    }
    for (int i = 1; i < 30; i++) {
        if (not need[i]) {
            continue;
        }
        if ((1 << i) > n) {
            cout << -1 << "\n";
            return 0;
        }
        p.push_back(1 << i);
    }
    int cur = p.size();

    vector<u8> vis(n + 1);
    for (auto x : p) {
        vis[x] = true;
    }

    for (int i = 0; i < cur; i++) {
        cout << p[i] << " ";
    }
    for (int i = 1; i <= n; i++) {
        if (not vis[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    cout << cur + (cur < n) << "\n";
    for (int i = 1; i <= cur; i++) {
        cout << i << " " << i << "\n";
    }
    if (cur < n) {
        cout << cur + 1 << " " << n << "\n";
    }

    return 0;
}