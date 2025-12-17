#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("g.in", "w", stdout);

    int t = 1;
    cout << t << endl;
    int n = 100;
    int k = 1e9;

    cout << n << " " << k << endl;

    for (int i = 0; i < n; i++) {
        int w = (rng() % k) + 1;
        int t = (rng() % n) + 1;

        cout << w << " " << t << "\n";
    }

    return 0;
}

/*
 2
 4 3
 3 2
 2 1
 3 2
 1 2
 2 10
 1 7
 4 20

1
10 4
4 1
4 1
4 1
4 1
4 1
4 1
4 1
4 1
4 1
3 2
*/