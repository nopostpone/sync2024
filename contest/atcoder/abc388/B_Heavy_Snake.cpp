#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, d;
    cin >> n >> d;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] * b[i];
    }

    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            c[j] += a[j];
        }
        cout << *max_element(c.begin(), c.end()) << "\n";
    }


    return 0;
}