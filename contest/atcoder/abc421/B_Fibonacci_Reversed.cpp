#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

i64 f(i64 x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 a[10]{};

    cin >> a[0] >> a[1];

    for (int i = 2; i < 10; i++) {
        a[i] = f(a[i - 1] + a[i - 2]);
    }
    cout << a[9] << "\n";

    return 0;
}