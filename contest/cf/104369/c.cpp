#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(),a.end());

    ll i=1,j=n;
    ll ans=0;
    while(i<j){
        ll num=min(a[i].second,a[j].second);
        ans+=num*(a[j].first-a[i].first);
        a[i].second-=num;
        a[j].second-=num;
        if(a[i].second==0) i++;
        if(a[j].second==0) j--;
    }
    cout << ans << "\n";
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
4
2003
1 2020
2023
2003
1 2020
2003
2345
0
3456
3000
4 3001 3003 3004 3008
3007
*/