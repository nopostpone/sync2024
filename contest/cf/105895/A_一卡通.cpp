#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool ok = true;

    if (s.substr(0, 2) != "21") {
        ok = false;
    }
    if (s[2] != '3' and s[2] != '4') {
        ok = false;
    }
    if (s.substr(5) == "0000") {
        ok = false;
    }

    cout << (ok ? "YES" : "NO") << "\n";

    return 0;
}