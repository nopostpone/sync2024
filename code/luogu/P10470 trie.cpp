#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 1e6;

int trie[N][26];
int cnt[N];
int tot = 0;

int newNode() {
    tot++;
    return tot;
}

void Insert(const string &s) {
    int p = 0;
    const int n = s.size();
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        if (not trie[p][x]) {
            trie[p][x] = newNode();
        }
        p = trie[p][x];
    }
    cnt[p]++;
}

int Query(const string &s) {
    int p = 0;
    int res = 0;

    const int n = s.size();
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        if (not trie[p][x]) {
            break;
        }
        res += cnt[trie[p][x]];
        p = trie[p][x];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        Insert(s);
    }

    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        cout << Query(t) << "\n";
    }

    return 0;
}