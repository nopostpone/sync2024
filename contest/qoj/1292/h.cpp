#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int p = n - 6;

    string t = s.substr(p);
    if (t == "mimasu") {
        t = "nde";
    } else if (t == "rimasu") {
        t = "tte";
    } else if (t == "bimasu") {
        t = "nde";
    } else if (t == "nimasu") {
        t = "nde";
    } else if (t == "kimasu") {
        if (s == "ikimasu") {
            cout << "itte\n";
            return;
        } else {
            t = "ite";
        }
    } else if (t == "gimasu") {
        t = "ide";
    } else {
        p--;
        assert(p >= 0);
        t = s.substr(p);

        if (t == "chimasu") {
            t = "tte";
        } else if (t == "shimasu") {
            t = "shite";
        }
    }

    s = s.substr(0, p) + t;

    cout << s << "\n";
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