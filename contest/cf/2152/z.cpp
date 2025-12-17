#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n * n + 1);
    ranges::iota(p, 0);

    do {
        for (int i = 0; i < n * n + 1; i++) {
            cerr << p[i] << " \n"[i == n * n];
        }
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}