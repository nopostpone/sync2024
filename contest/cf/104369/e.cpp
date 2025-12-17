#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e6 + 5;

int k;
struct Trie{

    int ansid = 0;
    string ans = "", cur = "";
    bool ok = false;
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
        cur = "";
        ansid = 0;
        ok = false;
        return;
    }

    void insert(const string &s){
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

    void dfs(int p, bool ok){
        // cout << cnt[p] << " " << k << " " << cur << " " << ans << endl;
        if(cnt[p] >= k){
            if(cnt[p] >= 2) ansid = p;

            int all = 0;
            for(int i = 0; i < 26; i++){
                if(son[p][i]) all += cnt[son[p][i]];
            }
            k -= f[p] + cnt[p] - all;

            if(k > 0){
                for(int i = 0; i < 26; i++){
                    if(son[p][i]){
                        k++;
                        cur += char('a' + i);
                        dfs(son[p][i], ok);
                        cur.pop_back();
                        if(k <= 0) return;
                    }
                }
            }else return;
        }else{
            if(cnt[p] >= 2) ansid = p;
            for(int i = 0; i < 26; i++){
                if(son[p][i]){
                    cur += char('a' + i);
                    dfs(son[p][i], false);
                    cur.pop_back();
                    if(k <= 0) return;
                }
            }
            if(ok) k -= cnt[p];
        }
        return;
    }

    void getans(int p){
        if(p == ansid){
            ok = true;
            ans = cur;
            return;
        }
        for(int i = 0; i < 26; i++){
            if(son[p][i]){
                cur += char('a' + i);
                getans(son[p][i]);
                cur.pop_back();
            }
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

    trie.dfs(0, true);
    trie.cur = "";
    trie.getans(0);

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

/*
1
6 6
aab
aac
aad
ab
ab
ac
*/