#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

constexpr int P = 998244353;

constexpr int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = (i64)a * a % P) {
        if (b & 1) {
            res = (i64)res * a % P;
        }
    }
    return res;
}
int inv(int x) {
    return power(x, P - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    int ans = 1;

    int cur = 0;
    int offset = 0;

    vector<int> cnt(n + 1);
    set<int> s;

    int num = 0;
    for (auto x : a) {
        if (x != -1) {
            if (x < offset) {
                ans = 0;
                break;
            }

            s.insert(x);
            cnt[x]++;
            num++;
            continue;
        }

        int mn = *s.begin();
        ans = (i64)ans * cnt[mn] % P;
        ans = (i64)ans * inv(num) % P;

        offset = mn;
        cnt[mn]--;
        num--;
        if (cnt[mn] == 0) {
            s.erase(mn);
        }
    }

    cout << ans << "\n";
}

/*
2
1 2 -1 -1

3
1 2 -1 -1 1 -1

4
1 -1 2 -1 3 -1 4 -1
*/