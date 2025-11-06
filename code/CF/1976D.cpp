#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    map<int, int> f;

    ll ans{};

    int now{};
    f[now]++;

    /**
     * 用 bal_i 表示 i 处左括号和右括号的差
     * 那么一个合法的 [l, r] 要满足以下两个条件
     * 1. 对于任意 l <= i <= r，有 bal_{l - 1} >= bal_i - bal_{l - 1}，否则右括号多了合不起来
     * 2. bal_r == bal_{l - 1} 左括号和右括号匹配
     * 
     * 用 std::map 维护 bal_i值 -> 数量的映射，每次都把不符合第一个条件的扔掉，O(n logn)
    */
    for (auto c : s) {
        if (c == '(') {
            now++;
        } else {
            now--;
        }
        ans += f[now];
        f[now]++;
        
        // x < bal_r - x
        while (f.begin()->first * 2 < now) {
            f.erase(f.begin());
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}