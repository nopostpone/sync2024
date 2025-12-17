#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr string zheng(const string &s) {
    return s.substr(0, s.find('.'));
}

constexpr string xiao(const string &s) {
    if (s.find('.') == string::npos) {
        return "000000";
    } else {
        string t = s.substr(s.find('.') + 1, 6);
        while (t.size() < 6) {
            t += '0';
        }
        return t;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string a, b;
    cin >> a >> b;

    string a1 = zheng(a), b1 = zheng(b);
    string a2 = xiao(a), b2 = xiao(b);

    cout << (a1 == b1 and a2 == b2 ? "YES" : "NO") << endl;
    
    return 0;
}