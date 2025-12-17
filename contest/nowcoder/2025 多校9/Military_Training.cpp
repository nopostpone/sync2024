#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    i64 sx1, sy1, sx2, sy2, tx1, tx2, ty1, ty2;

    cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;

    auto work = [&](i64 u1, i64 v1, i64 u2, i64 v2) {
        i64 mn = min(abs(u1 - u2), abs(v1 - v2));
        return abs(u1 - u2) + abs(v1 - v2) - mn;
    };

    i64 ans = 0;

    if (sx1 == sx2 and tx1 == tx2) {
        ans = 2 * work(sx1, min(sy1, sy2), tx1, min(ty1, ty2));
    } else if (sy1 == sy2 and ty1 == ty2) {
        ans = 2 * work(min(sx1, sx2), sy1, min(tx1, tx2), ty1);
    } else {
        
        if (tx1 == tx2) {
            ans = 2 * min({
                work(max(sx1, sx2), sy1, tx1, min(ty1, ty2)), 
                work(min(sx1, sx2), sy1 - 1, tx1, min(ty1, ty2)),
                work(max(sx1, sx2), sy1 - 1, tx1, min(ty1, ty2)), 
                work(min(sx1, sx2), sy1, tx1, min(ty1, ty2)),
            }) + 1;
        } else {
            ans = 2 * min({
                work(sx1, min(sy1, sy2), min(tx1, tx2), ty1), 
                work(sx1, max(sy1, sy2), min(tx1, tx2), ty1),
                work(sx1 - 1, min(sy1, sy2), min(tx1, tx2), ty1), 
                work(sx1 - 1, max(sy1, sy2), min(tx1, tx2), ty1),
            }) + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}