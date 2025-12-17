#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int ans;
    if (a % 2 == b % 2) {
        ans = (std::abs(a - b) - 2) / 2;
    } else {
        int u = a / 2;
        int v = b / 2;
        ans = u + v;
    }
    cout << ans << endl;

    return 0;
}