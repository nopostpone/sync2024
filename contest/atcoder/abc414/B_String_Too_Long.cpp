#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        char c;
        i64 l;
        cin >> c >> l;

        if (l > 100) {
            ok = false;
            break;
        }
        s += string(l, c);
        if (s.size() > 100) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << s << "\n";
    } else {
        cout << "Too Long\n";
    }

    return 0;
}