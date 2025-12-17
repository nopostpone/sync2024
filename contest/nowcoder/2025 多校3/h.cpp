#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
    }

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        x--;
    }

    
    

    return 0;
}