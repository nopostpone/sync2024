#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
auto findPrime(int n) {
    while (not isPrime(n)) {
        n++;
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int o, n, m;
    cin >> o >> n >> m;

    const auto p = findPrime(m);

    auto Encode = [&]() {
        vector<int> ori(3 * m);
        for (int i = 0; i < 3 * m; i++) {
            ori[i] = i % m;
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;

            auto a = ori;
            rotate(a.begin() + m, a.begin() + m + x, a.begin() + m + p);
            
            for (int j = 0; j < 3 * m; j++) {
                cout << a[j] + 1 << " \n"[j == 3 * m - 1];
            }
        }
    };

    auto Decode = [&]() {
        for (int _ = 0; _ < n; _++) {
            vector<int> a(3 * m);
            for (auto &x : a) {
                cin >> x;
            }

            vector<int> ori(p);
            for (int i = 0; i < p; i++) {
                ori[i] = a[i % m];
            }
            
            vector<int> b(a.begin() + m, a.begin() + m + p);
            vector<int> f(p + 1);
            for (int i = 1, j = 0; i < p; i++) {
                while (j > 0 and b[i] != b[j]) {
                    j = f[j];
                }
                j += (b[i] == b[j]);
                f[i + 1] = j;
            }

            for (int i = 0, j = 0; i < 2 * p; i++) {
                auto x = ori[i % p];

                while (j > 0 and x != b[j]) {
                    j = f[j];
                }
                j += (x == b[j]);
                if (j == p) {
                    cout << (i - p + 2) << "\n";
                    break;
                }
            }
        }
    };

    o == 1 ? Encode() : Decode();
}