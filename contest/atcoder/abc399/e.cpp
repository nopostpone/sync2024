#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s, t;
    cin >> n >> s >> t;

    array<int, 26> swi{-1};
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (swi[c] == -1) {
            swi[c] = t[i] - 'a';
        } else {
            if (swi[c] != t[i] - 'a') {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    

    return 0;
}