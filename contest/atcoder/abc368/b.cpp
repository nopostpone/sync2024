#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    int cnt = 0;

    while (a[1] > 0) {
        a[0]--;
        a[1]--;
        cnt++;
        sort(a.begin(), a.end(), greater<>());
    }
    cout << cnt;

    
    return 0;
}