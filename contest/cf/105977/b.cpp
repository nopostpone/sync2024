#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> op1(n + 30), op3(n + 30);
    for (int g = 0; g <= n / 8; g++) {
        int r = min(n - 4 * g - p, (n - 8 * g) / 4);
        if (r < 0) {
            continue;
        }
        op1[(n + 1) / 2 - 3 * g - r]++;
        op1[(n + 1) / 2 - 3 * g + 1]--;
        
        op3[n - 7 * g - 3 * r + 1]--;
        op3[n - 7 * g + 4]++;
    }

    for (int i = 1; i <= n; i++) {
        op1[i] += op1[i - 1];
    }
    for (int i = 3; i <= n; i++) {
        op3[i] += op3[i - 3];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += op1[i] + op3[i];
        cout << ans << " \n"[i == n];
    }

    return 0;
}

/*
8 7
0 0 1 2 2 1 1 1

10 8
0 0 1 2 2 2 2 1 1 1

12 1
0 1 2 2 3 3 2 2 2 1 1 1
*/