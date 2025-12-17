#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<double>> a(64);

    for (int i = 0; i < 64; i++) {
        vector<double> b(64);
        for (int j = 0; j < 64; j++) {
            if (i < 32) {
                if (j < 32) {
                    if (i == j) {
                        b[j] = 1;
                    } else {
                        b[j] = 0;
                    }
                } else {
                    if (i == 31) {
                        int t = j - 32;
                        if (n & (1 << t)) {
                            b[j] = 1;
                        } else {
                            b[j] = 0;
                        }
                    } else {
                        if (j <= 31 + i) {
                            b[j] = 1;
                        } else {
                            b[j] = 0;
                        }
                    }
                }
            } else {
                if (j < 32) {
                    if (i - j == 32) {
                        b[j] = 1;
                    } else {
                        b[j] = 0;
                    }
                } else {
                    if ((i == j && i != 63) || (i != 63 && j == 63)) {
                        b[j] = 1;
                    } else {
                        b[j] = 0;
                    }
                }
            }
        }
        a[i] = b;
    }

    cout << 64 << endl;
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // cout << det(a,64) << endl;

    // gauss(a,64,64);

    return 0;
}
