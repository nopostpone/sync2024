#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t = "nowcoder";
    multiset<char> s;
    for (auto c : t) {
        s.insert(c);
    }
    for (int i = 0; i < 8; i++) {
        char c;
        cin >> c;
        s.extract(c);
    }

    cout << (s.empty() ? "happy new year" : "I AK IOI");

    return 0;
}