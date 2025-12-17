#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 2e5 + 1;

int trie[N][26], cnt[N];
int tot;

void Insert(const string &s) {
    int p = 0;
    for (char c : s) {
        int x = c - 'a';
        if (trie[p][c] == 0) {
            trie[p][c] = ++tot;
        }
        p = trie[p][c];
        cnt[p]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;

        Insert(s);
    }

    i64 ans = 0;
    for (int i = 1; i <= tot; i++) {
        i64 a = cnt[i] / 2;
        ans += a * (cnt[i] - a);
    }
    cout << ans << "\n";

    return 0;
}