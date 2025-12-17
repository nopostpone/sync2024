#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

i64 tenPow[15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tenPow[0] = 1;
    for (int i = 1; i < 15; i++) {
        tenPow[i] = tenPow[i - 1] * 10;
    }

    int a;
    i64 n;
    cin >> a >> n;

    int len = to_string(n).size();

    // constexpr auto check = [](const string &s, int a) {
    //     auto x = stoll(s);

    //     vector<int> d;
    //     while (x) {
    //         d.push_back(x / a);
    //         x /= a;
    //     }

    //     for (int l = 0, r = d.size() - 1; l < r; l++, r--) {
    //         if (d[l] != d[r]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // };

    constexpr auto check = [](i64 x, int a) {
        vector<int> d;
        while (x) {
            d.push_back(x % a);
            x /= a;
        }

        for (int l = 0, r = d.size() - 1; l < r; l++, r--) {
            if (d[l] != d[r]) {
                return false;
            }
        }
        return true;
    };


    i64 ans = 0;
    for (int l = 1; l <= len; l++) {
        int half = (l + 1) / 2;

        i64 s = tenPow[half - 1];
        i64 t = tenPow[half] - 1;

        for (i64 x = s; x <= t; x++) {
            string tem = to_string(x);

            string rev = tem;
            if (l % 2 == 1) {
                rev.pop_back();
            }
            reverse(rev.begin(), rev.end());
            tem += rev;

            i64 v = stoll(tem);
            if (v > n) {
                continue;
            }

            if (check(v, a)) {
                ans += v;
            }

            // if (check(tem)) {
            // }

            
        }
    }
    cout << ans << "\n";
    

    return 0;
}
