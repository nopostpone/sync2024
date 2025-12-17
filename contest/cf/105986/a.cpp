#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;

std::ostream &operator<<(std::ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (b == 0) {
        cout << max<i64>(n, (i64)n * a) << "\n";
    } else {
        i64 bound = ((i64)n * b + a - 1) / (2 * b);
        bound = min(bound, (i64)n);

        auto f = [&](i64 x) {
            i64 res = (i64)-b * x * x;
            res += ((i64)n * b + a - 1) * x;
            res += n;
            return res;
        };

        auto ans = f(bound);

        if (bound < n) {
            ans = max(ans, f(bound + 1));
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
3
1 1 1
7 2 3
5 6 1

3
5 3 2
5 5 3
1 4 1
*/