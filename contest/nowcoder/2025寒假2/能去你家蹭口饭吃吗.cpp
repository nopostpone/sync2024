#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ranges::sort(a, greater());
    int m = (n + 1) / 2;

    cout << a[m - 1] - 1 << "\n";

    return 0;
}