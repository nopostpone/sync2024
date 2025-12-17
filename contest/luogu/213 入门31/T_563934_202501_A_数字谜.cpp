#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    a %= 10;

    cout << (a > b ? 10 - a + b : b - a);

    return 0;
}