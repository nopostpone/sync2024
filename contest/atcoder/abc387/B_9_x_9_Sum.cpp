#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int x;
    cin >> x;

    int ans{};

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j != x) {
                ans += i * j;
            }
        }
    }
    cout << ans << endl;

    return 0;
}