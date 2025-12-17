#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;


    for (int i = n - 1; ~i and d > 0; i--) {
        if (s[i] == '.') {
            continue;
        }
        d--;
        s[i] = '.';
    }

    cout << s << endl;
    
    return 0;
}