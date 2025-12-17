#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S = "uoiae";

void solve() {
    int n;
    cin >> n;

    if (n <= 5) {
        cout << S.substr(0, n) << "\n";
        return;
    }

    vector<int> a(5);
    int j = 0;
    while (n--) {
        a[j]++;
        j = (j + 1) % 5;
    }


    for (int i = 0; i < a[0]; i++) {
        cout << "a";
    }
    for (int i = 0; i < a[1]; i++) {
        cout << "e";
    }
    for (int i = 0; i < a[2]; i++) {
        cout << "i";
    }
    for (int i = 0; i < a[3]; i++) {
        cout << "o";
    }
    for (int i = 0; i < a[4]; i++) {
        cout << "u";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 0; i < 1000; i++) {
        S.push_back('e');
    }

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}