#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// 预处理阶乘和逆阶乘，用于快速计算组合数
vector<int> fact, inv_fact;

void precompute_factorials(int max_n) {
    fact.resize(max_n + 1);
    inv_fact.resize(max_n + 1);
    fact[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    inv_fact[max_n] = [&]() {
        int res = 1, base = fact[max_n], exp = MOD - 2;
        while (exp) {
            if (exp & 1) res = 1LL * res * base % MOD;
            base = 1LL * base * base % MOD;
            exp >>= 1;
        }
        return res;
    }();
    for (int i = max_n - 1; i >= 0; --i) {
        inv_fact[i] = 1LL * inv_fact[i + 1] * (i + 1) % MOD;
    }
}

int comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A) cin >> a;

    // 预处理组合数
    precompute_factorials(K);

    // 计算前缀和 S
    vector<int> S(N + 1);
    for (int i = 1; i <= N; ++i) {
        S[i] = (S[i - 1] + A[i - 1]) % MOD;
    }

    // 预处理 S[j]^d (0 <= d <= K)
    vector<vector<int>> pow_s(N + 1, vector<int>(K + 1));
    for (int j = 0; j <= N; ++j) {
        pow_s[j][0] = 1;
        for (int d = 1; d <= K; ++d) {
            pow_s[j][d] = 1LL * pow_s[j][d - 1] * S[j] % MOD;
        }
    }

    // 预处理组合数系数 C(K,m) * (-1)^m
    vector<int> coeff(K + 1);
    for (int m = 0; m <= K; ++m) {
        coeff[m] = 1LL * comb(K, m) * ((m % 2 == 0) ? 1 : MOD - 1) % MOD;
    }

    // sum_pows[m] = sum_{i=0}^{r-1} S[i]^m
    vector<int> sum_pows(K + 1);
    sum_pows[0] = 1;  // S[0]^0 = 1

    int ans = 0;
    for (int r = 1; r <= N; ++r) {
        // 计算当前r的贡献
        int contribution = 0;
        for (int m = 0; m <= K; ++m) {
            int d = K - m;
            contribution = (contribution + 1LL * coeff[m] * pow_s[r][d] % MOD * sum_pows[m] % MOD) % MOD;
        }
        ans = (ans + contribution) % MOD;

        // 更新sum_pows
        for (int m = 0; m <= K; ++m) {
            sum_pows[m] = (sum_pows[m] + pow_s[r - 1][m]) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}