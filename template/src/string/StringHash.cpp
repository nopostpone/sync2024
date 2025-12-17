#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using Hash = array<int, 2>;

constexpr int P = 998244353;
constexpr Hash base = {567, 1234}; // any

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = s.size();

    vector<Hash> h(n + 1), p(n + 1);
    p[0] = {1, 1};
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            h[i + 1][j] = (i64(base[j]) * h[i][j] + s[i]) % P;
            p[i + 1][j] = (i64(base[j]) * p[i][j]) % P;
        }
    }

    auto get = [&](int l, int r) {
        Hash res{};
        for (int i = 0; i < 2; i++) {
            res[i] = (h[r][i] + 1ll * (P - h[l][i]) * p[r - l][i]) % P;
        }
        return res;
    };

    return 0;
}