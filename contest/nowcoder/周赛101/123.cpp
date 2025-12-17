#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 快速幂，计算 a^e % m
ll mod_pow(ll a, ll e, ll m) {
    ll r = 1 % m;
    a %= m;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % m;
        a = (__int128)a * a % m;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll base, c0;
    int mod;
    cin >> base >> c0 >> mod;
    int q;
    cin >> q;

    // pos[x] = 第一次出现 x 的下标（1-based），-1 表示未出现
    vector<int> pos(mod, -1);
    vector<int> seq;           // 存放 c1, c2, ...
    seq.reserve(mod + 1);

    // 生成序列并找环
    ll last = c0;
    int mu = -1, L = -1;
    for (int i = 1; ; ++i) {
        int cur = (int)mod_pow(base, last, mod);
        if (pos[cur] != -1) {
            mu = pos[cur];      // 环的起始位置
            L  = i - pos[cur];  // 环长
            break;
        }
        pos[cur] = i;
        seq.push_back(cur);
        last = cur;
    }

    // 前缀和 S[i] = sum_{j=1..i} seq[j-1] （全程对 mod 取余）
    int N = seq.size();
    vector<int> S(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        S[i] = S[i-1] + seq[i-1];
        if (S[i] >= mod) S[i] -= mod;
    }
    // 环内一整段的和
    int sum_cycle = (S[mu-1 + L] - S[mu-1] + mod) % mod;

    cerr << sum_cycle << endl;

    // 回答查询
    while (q--) {
        ll k;
        cin >> k;
        int ans;
        if (k <= N) {
            // 在前缀里，直接取
            ans = S[k];
        } else if (k < mu) {
            // 在进入环之前
            ans = S[k];
        } else {
            // 已经进入环
            ll t = k - (mu - 1);
            ll cnt = t / L;
            int rem = t % L;
            ll part1 = S[mu-1];
            ll part2 = (cnt % mod) * sum_cycle % mod;
            ll part3 = S[mu-1 + rem] - S[mu-1];
            part3 = (part3 + mod) % mod;
            ans = (part1 + part2 + part3) % mod;
        }
        cout << ans << "\n";
    }

    return 0;
}
