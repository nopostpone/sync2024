#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M=998244353;

void solve(){
    int l, r;
    cin >> l >> r;
    if(r & 1){
        if(l & 1) cout << "Alice\n";
        else cout << "Bob\n";
    }else{
        int x = r / 2;
        if(x % 2 == 0) x--;
        if(x >= l){
            if(l & 1) cout << "Alice\n";
            else cout << "Bob\n";
        }else{
            if(l & 1) cout << "Bob\n";
            else cout << "Alice\n";
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T-->0) solve();
}