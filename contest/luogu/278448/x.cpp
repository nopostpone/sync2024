
/*
 * Author: Xiangmy
 * Created: 2024-03-22 11:57
 * Problem:
 * Description: 模拟
 * 分为 7 ~ i，i，i-1 ~ 0 三段分别计算 i-1 ~ 0 会被加 i 轮
 */
// #pragma GCC optimize(2)
// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << (x) << ' '
// #define x first
// #define y second
typedef long long LL;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

using i64 = long long;

const LL cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};
vector<LL> pre(17);

void init() {
    for (int i = 0; i < 16; ++i) {
        pre[i + 1] += pre[i] + cost[i];
    }
}

void solve() {
    LL t;
    cin >> t;
    string s;
    cin >> s;
    LL x = 0;
    for (int i = 0; i < 8; ++i) { // 16进制转10进制
        x *= 16;
        if (isdigit(s[i]))
            x += s[i] - '0';
        else
            x += s[i] - 'A' + 10;
    }

    auto calc = [&](LL n) -> LL {
        LL res = 0;
        if (n == (1ll << 32)) {
            return pre[16] * (1ll << 28) * 8; // 8位每位都会加16^7次(其他位全排列)
        }
        LL s = 0;
        for (int i = 7; i >= 0; --i) {
            int d = n >> (4 * i) & 15;        // 第 i 位的值。& 15 只取最后4位
            // res += pre[d] * (1ll << (4 * i)); // 第 i 位的值被加了几次
            // res += s * d * (1ll << (4 * i));  // 第 7 ~ i+1 位被加的次数fd

            if (i != 0) {                    // i ~ 0 位一共i位被加了几轮
                res += pre[16] * d * (1ll << (4 * (i - 1))) * i;
            }
            s += cost[d];
        }

        cerr << n << " " << res << endl;
        return res;
    };

    LL ans = 0;
    LL st = x, ed = x + t;

    cerr << (1ll << 32) << endl;

    cerr << x + t - (1ll << 32) << endl;

    if (ed <= (1ll << 32)) {
        ans += calc(ed);
    } else { // 溢出 FFFFFFFF 的情况
        ans += calc(ed - (1ll << 32));
        ans += calc(1ll << 32);
    }
    ans -= calc(st);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); // 交互题不用
    cout.tie(0);
    // cout << fixed << setprecision(6);
    // cout << setw(4) << setfill('0');
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        // cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        solve();
    }
    return 0;
}
