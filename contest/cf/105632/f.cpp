#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector f(4, vector<i64>(n + 1));
    for (int i = 0; i < 3; i++) {
        f[i + 1][0] = f[i][n];
        for (int j = 0; j < n; j++) {
            f[i + 1][j + 1] = max(f[i + 1][j], i64(i) * k + a[j] - 1) + b[j];
        }
    }

    i64 sum = accumulate(b.begin(), b.end(), i64());
    sum = max(sum, (i64)k);

    auto output = [k](i64 time) {
        cout << (time - 1) / k + 1 << " " << time - (time - 1) / k * k << "\n";
    };

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x <= 3) {
            output(f[x][y]);
        } else {
            output(f[3][y] + sum * (x - 3));
        }
    }
}

/*
2 5 6
1 1
4 3
1 1
1 2
2 1
2 2
3 1
3 2

    1 1
    2 1
    2 2
    3 1
    3 2
    4 1

3 10 5
2 4
3 1
10 7
2 2
7 1
4 3
5 2
28 3

    3 1
    8 10
    6 2
    6 7
    34 10
*/