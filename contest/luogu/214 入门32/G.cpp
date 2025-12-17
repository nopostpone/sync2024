#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 16;
using B = bitset<N>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = s.size();

    vector<int> a;
    int p = n;

    if (s[0] != ':') {
        a.push_back(0);
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == ':') {
            if (s[i + 1] == ':') {
                p = i;
            } else {
                a.push_back(i + 1);
            }
        }
    }

    array<B, 8> ans;
    int cur = 0;

    for (auto i : a) {
        int t = s.find_first_of(':', i);
        unsigned short x = stoi(s.substr(i, t - i), 0, 16);

        ans[cur + (i > p) * (8 - a.size())] = B(x);
        cur++;
    }

    for (int i = 0; i < 8; i++) {
        cout << ans[i];
    }

    return 0;
}