#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> p(n), q(n);
    auto check = [&]() {
        for (int i = 0; i < n; i++) {
            int x = p[i];
            q[a[x]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (p[i] == i or q[i] == i) {
                return false;
            }
        }
        return true;
    };

    ranges::iota(p, 0);
    if (n <= 8) {

        do {
            if (check()) {
                cout << "Possible\n";
                for (int i = 0; i < n; i++) {
                    cout << p[i] + 1 << " \n"[i == n - 1];
                }
                for (int i = 0; i < n; i++) {
                    cout << q[i] + 1 << " \n"[i == n - 1];
                }
                return;
            }
        } while (next_permutation(p.begin(), p.end()));
    } else {
        for (int i = 0; i < 100; i++) {
            random_shuffle(p.begin(), p.end());
            if (check()) {
                cout << "Possible\n";
                for (int i = 0; i < n; i++) {
                    cout << p[i] + 1 << " \n"[i == n - 1];
                }
                for (int i = 0; i < n; i++) {
                    cout << q[i] + 1 << " \n"[i == n - 1];
                }
                return;
            }
        }
    }

    cout << "Impossible\n";
    
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