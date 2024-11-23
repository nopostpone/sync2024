#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long HALF = 499122177;
template <typename T>
struct binary_indexed_tree {
    int N;
    vector<T> BIT;
    binary_indexed_tree(int N) : N(N), BIT(N + 1, 0) {
    }
    void add(int i, T x) {
        i++;
        while (i <= N) {
            BIT[i] += x;
            i += i & -i;
        }
    }
    T sum(int i) {
        T ans = 0;
        while (i > 0) {
            ans += BIT[i];
            i -= i & -i;
        }
        return ans;
    }
    T sum(int L, int R) {
        return sum(R) - sum(L);
    }
};
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    vector<long long> inv(N + 1);
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    }
    binary_indexed_tree<long long> BIT(N);
    long long inv0 = 0;
    for (int i = 0; i < N; i++) {
        inv0 += BIT.sum(P[i] + 1, N);
        BIT.add(P[i], 1);
    }
    long long sum = 0;
    long long inv1 = 0;
    binary_indexed_tree<long long> BIT2(N);
    for (int i = 0; i < K; i++) {
        inv1 += BIT2.sum(P[i] + 1, N);
        BIT2.add(P[i], 1);
    }
    for (int i = 0; i <= N - K; i++) {
        sum += (inv0 - inv1 + (long long)K * (K - 1) / 2 % MOD * HALF % MOD + MOD) % MOD;
        sum %= MOD;
        if (i < N - K) {
            inv1 += BIT2.sum(P[i + K] + 1, N);
            BIT2.add(P[i + K], 1);
            inv1 -= BIT2.sum(P[i]);
            BIT2.add(P[i], -1);
        }
    }
    sum *= inv[N - K + 1];
    sum %= MOD;
    cout << sum << endl;
}