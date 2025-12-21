#include <bits/stdc++.h>
using namespace std;

void output(bool isOr, int x, int y) {
    cout << "&|"[isOr] << " " << x + 1 << " " << y + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    cout << 6 * n - 6 << "\n";

    int tot = n;
    vector<int> a(n);
    a[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        output(true, i, a[i + 1]);
        output(true, tot++, a[i + 1]);

        a[i] = tot++;
    }

    vector<int> f(n), b(n);
    f[0] = b[0] = a[0];
    for (int i = 1; i < n; i++) {
        output(false, f[i - 1], a[i]);
        f[i] = tot++;

        output(true, f[i - 1], a[i]);
        b[i] = tot++;
    }

    output(true, a[0], a[1]);
    output(true, tot++, b[1]);
    for (int i = 2; i < n; i++) {
        output(true, tot++, a[i]);
        output(true, tot++, b[i]);
    }
}