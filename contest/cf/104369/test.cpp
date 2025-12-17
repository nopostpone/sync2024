#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL INF = 1e18;

const int N = 1e6 + 5;


int k;
struct Trie{

    string ans = "";
    int idx, son[N][26], f[N], cnt[N];

    void init(){
        for(int i = 0; i <= idx; i++)
            for(int j = 0; j < 26; j++)
                son[i][j] = 0;
        for(int i = 0; i <= idx; i++){
            cnt[i] = 0;
            f[i] = 0;
        }
        idx = 0;
        ans = "";
        return;
    }

    void insert(string s){
        int p = 0;
        cnt[p]++;
        for(auto c : s){
            int x = c - 'a';
            if(!son[p][x]){
                son[p][x] = ++idx;
                f[p]++;
            }
            p = son[p][x];
            cnt[p]++;
        }
        return;
    }

    void dfs(int p, string cur){
        // cout << cnt[p] << " " << k << " " << cur << " " << ans << endl;
        if(cnt[p] >= k){
            if(cnt[p] >= 2) ans = max(ans, cur);

            int all = 0;
            for(int i = 0; i < 26; i++){
                if(son[p][i]) all += cnt[son[p][i]];
            }
            k -= f[p] + cnt[p] - all;

            if(k > 0){
                for(int i = 0; i < 26; i++){
                    if(son[p][i]){
                        k++;
                        dfs(son[p][i], cur + char('a' + i));
                        if(k <= 0) return;
                    }
                }
            }else{
                if(cnt[p] >= 2) ans = max(ans, cur);
                return;
            }
        }else{
            if(cnt[p] >= 2) ans = max(ans, cur);
            for(int i = 0; i < 26; i++){
                if(son[p][i]){
                    dfs(son[p][i], cur + char('a' + i));
                    if(k <= 0) return;
                }
            }
            k -= cnt[p];
        }
        return;
    }

}trie;

void solve() {
    int n;
    cin >> n >> k;

    trie.init();
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        trie.insert(s);
    }

    trie.dfs(0, "");

    if(trie.ans.empty()) cout << "EMPTY\n";
    else cout << trie.ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
/*
1
6 4
ab
aba
abab
abac
abb
abc
*/