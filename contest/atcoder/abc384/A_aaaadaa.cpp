#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    char c1, c2;
    cin >> n >> c2 >> c1;

    string s;
    cin >> s;

    for (auto &i : s) {
        if (i != c2) {
            i = c1;
        }
    }
    cout << s;
    
    return 0;
}