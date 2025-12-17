#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

string s1 = "OBAFGKM";

void solve() {
    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "same\n";
        return;
    }

    int pa = s1.find(a.front());
    int pb = s1.find(b.front());

    char na = a[1], nb = b[1];

    if (pa < pb) {
        cout << "hotter\n";
    } else if (pa > pb) {
        cout << "cooler\n";
    } else {
        cout << (na < nb ? "hotter\n" : "cooler\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
 5
 O2 O7
 M9 M2
 G2 G2
 A0 B9
 F8 K1
*/