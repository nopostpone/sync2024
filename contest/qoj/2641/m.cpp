#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int n = 8;

    array<int, n> a, b;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    vector<int> ord(n);
    ranges::iota(ord, 0);
    
    double ans = 0;
    
    do {
        array<double, n> p {};
        p.fill(1);
        
        auto get = [&](int i, int j) {
            assert(i < j);
            int u = ord[i];
            int v = ord[j];

            return double(a[u]) / double(a[u] + b[v]);
        };

        for (int i = 0; i < n; i += 2) {
            double x = get(i, i + 1);
            p[i] *= x;
            p[i + 1] *= 1 - x;
        }

        array<double, n> np {};
        for (int i = 0; i < n; i += 4) {
            for (int j = 0; j < 2; j++) {
                for (int k = 2; k < 4; k++) {
                    double x = get(i + j, i + k);
                    np[i + j] += p[i + j] * p[i + k] * x;
                    np[i + k] += p[i + j] * p[i + k] * (1 - x);
                }
            }
        }
        p = np;
        np.fill(0);

        for (int i = 0; i < 4; i++) {
            for (int j = 4; j < n; j++) {
                double x = get(i, j);
                np[i] += p[i] * p[j] * x;
                np[j] += p[i] * p[j] * (1 - x);
            }
        }

        p = move(np);

        for (int i = 0; i < n; i++) {
            if (ord[i] == 0) {
                ans = max(ans, p[i]);
                break;
            }
        }
        
    } while (next_permutation(ord.begin(), ord.end()));

    cout << fixed << setprecision(10) << ans << "\n";
}

/*
10 80
20 70
30 60
40 50
50 40
60 30
70 20
80 10

100 100
100 100
100 100
100 100
100 100
100 100
100 100
100 100
*/