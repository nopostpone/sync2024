#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

string t = " nya";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << n << t << "\n";

    string _;
    getline(cin, _);
    while (n--) {
        string s;
        getline(cin, s);
        cout << s << t << "\n";
    }

    return 0;
}