#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    for (int k = 0; k <= 1e6; k++) {
        i64 cur = stoll(n + to_string(k));
        if (cur % 8 == 0) {
            cout << k << "\n";
            return 0;
        }
    }

    return 0;
}