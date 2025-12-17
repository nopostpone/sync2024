#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 1e6 + 1;
int trie[N][26];
int cnt[N];

int tot;

void Insert(const string &s) {
    const int n = s.size();
    int p = 0;

    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        if (not trie[p][x]) {
            tot++;
            trie[p][x] = tot;
        }
        p = trie[p][x];
        cnt[p]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    int maxlen = 0;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        Insert(s[i]);
        ans += 2 * s[i].size();
        maxlen = max<int>(maxlen, s[i].size());
    }
    ans -= maxlen;

    for (int i = 1; i <= tot; i++) {
        ans -= 2 * (cnt[i] - 1);
    }

    int l, r;
    cin >> l >> r;

    cout << ans << "\n";

    return 0;
}