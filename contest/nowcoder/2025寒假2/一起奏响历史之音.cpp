#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    bool ok = true;
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        if (x != 1 and x != 2 and x != 3 and x != 5 and x != 6) {
            ok = 0;
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";

    return 0;
}