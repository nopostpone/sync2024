#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] /= 100;
    }

    vector dp0(n + 1, vector<double>(n + 1));
    dp0[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            dp0[i][j] += dp0[i - 1][j] * (1 - p[i - 1]);
            dp0[i][j + 1] += dp0[i - 1][j] * p[i - 1]; 
        }
    }

    // 开一个箱子，获得 0~n 个稀有牌的概率
    auto f = dp0[n];

    // 获得 0~x 个稀有牌，开箱子数量的期望
    vector<double> g(x + 1);
    for (int i = 1; i <= x; i++) {
        double sum{1.}, dex{f[0]};
        for (int j = 0; j < i; j++) {
            sum += f[j] * g[i - j];
        }
        g[i] = sum / (1 - dex);
    }

    cout << fixed << setprecision(20) << g[x] << "\n";

    return 0;
}