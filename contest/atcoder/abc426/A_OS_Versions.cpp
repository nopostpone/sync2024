#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

map<string, int> f = {{"Ocelot", 1}, {"Serval", 2}, {"Lynx", 3}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    cout << (f[s] >= f[t] ? "Yes" : "No") << "\n";

    return 0;
}