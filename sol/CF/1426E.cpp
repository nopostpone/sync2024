#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    array<int, 3> a, b;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }

    int x = min(a[0], b[1]);
    int y = min(a[1], b[2]);
    int z = min(a[2], b[0]);

    int u = min(a[0], n - b[1]);
    int v = min(a[1], n - b[2]);
    int w = min(a[2], n - b[0]);

    cout << n - u - v - w << " "
         << x + y + z << "\n";

    return 0;
}