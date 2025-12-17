#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

string f = "02468";

void solve() {
    string n;
    cin >> n;

    for (auto x : f) {
        int p = n.find(x);
        if (p == -1) {
            continue;
        }
        
        swap(n[p], n[4]);
        cout << n << "\n";
        return;
    }
    cout << 13579 << "\n";
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
5
12345
12345
12345
12345
13579

12345
54321
13524
45123
97531
*/