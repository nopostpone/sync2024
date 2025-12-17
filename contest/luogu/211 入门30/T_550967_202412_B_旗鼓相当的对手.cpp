#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<array<int, 2>> a(4);
        for (int j : {0, 1}) {
    for (int i = 0; i < 4; i++) {
            cin >> a[i][j];
    }
        }

    int cnt{};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (a[i][0] == a[j][0] or a[i][1] == a[j][1]) {
                continue;
            }
            if ((a[i][0] > a[j][0]) xor (a[i][1] > a[j][1])) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;


    
    return 0;
}