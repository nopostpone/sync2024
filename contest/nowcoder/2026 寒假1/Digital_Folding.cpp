#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

string rev(string s) {
    while (not s.empty() and s.back() == '0') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    return s;
}

i64 ten[16];

void solve() {
    string l, r;
    cin >> l >> r;
    
    if (l == r) {
        cout << rev(r) << "\n";
        return;
    }
    int n = r.size();

    auto vl = stoll(l);
    auto vr = stoll(r);

    if (vr == ten[n - 1]) {
        vr--;
        r = string(n - 1, '9');
        n--;
    }
    
    if (l.size() < r.size()) {
        l = to_string(ten[n - 1]);
        vl = ten[n - 1];
    }
    auto check = [&](string s) {
        auto vs = stoll(s);
        return vl <= vs and vs <= vr;
    };

    for (int i = n - 1; i >= 0; i--) {
        bool f = 0;
        for (int d = 9; d >= 0; d--) {
            string nl = l;
            nl[i] = '0' + d;
            if (check(nl)) {
                l = nl;
                f = true;
                break;
            }
        }
    }
    cout << rev(l) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ten[0] = 1;
    for (int i = 1; i < 16; i++) {
        ten[i] = ten[i - 1] * 10;
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}