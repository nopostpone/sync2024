#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = s.size();
    array<int, 26> ans{};

    for (int i = 0; i < 26; i++) {
        for (auto c : s) {
            int x = c - 'A';
            x = (x + i) % 26;

            ans[i] += cnt[x];
        }
    }
    cout << ranges::max(ans) << "\n";

    return 0;
}