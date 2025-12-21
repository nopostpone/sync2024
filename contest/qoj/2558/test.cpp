#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const LL MOD = 1e9 + 7;

LL qpow(LL base, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res * base % MOD;
        base = base * base % MOD;
        b >>= 1; 
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; LL m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    bool ok = false;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < n && a[i] > 1) ok = true;
        if(a[i] == -1) cnt++;
    }

    if(ok){
        cout << qpow(m, cnt);
        return 0;
    }

    int l,r;
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            r=i;
            while(i+1<=n && a[i+1]==-1) r++;

            cout << l << " " << r << endl;
        }

        i=r;
    }

    //LL ans = ((qpow(m, cnt) - dif % MOD) + MOD) % MOD;

    //cout << ans;
    return 0;
}
/*
2 2
-1 -1
*/

/*
6 10
-1 -1 -1 -1 1 7
*/