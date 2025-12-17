#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, p;
    cin >> n >> p;

    set<int> s;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (y == 1) {
            s.insert(x);
        }
    }
    
    cout << s.size() << endl;

    return 0;
}