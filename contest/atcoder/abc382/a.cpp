#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    int ori = 0;
    for (auto i : s) {
        ori += i == '.';
    }

    cout << min(n, ori + d);
    
    return 0;
}