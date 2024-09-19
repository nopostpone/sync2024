#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ask(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    int r;
    cin >> r;
    assert(r != -1);

    return r;
}

void solve() {
    int n;
    cin >> n;

    vector<int> good, bad;

    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = ask(i, (i + 1) % n, (i + 2) % n);
    }

    for (int i = 1; i < n; i++) {
        if (a[i] xor a[i - 1]) {
            if (a[i]) {
                good.push_back((i + 2) % n);
                bad.push_back(i - 1);
            } else {
                bad.push_back((i + 2) % n);
                good.push_back(i - 1);
            }
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i == good.front() or i == bad.front()) {
            continue;
        }
        bool r = ask(good.front(), bad.front(), i);
        if (r) {
            good.push_back(i);
        } else {
            bad.push_back(i);
        }
    }
    
    cout << "! " << bad.size() << " ";
    for (int i : bad) {
        cout << i + 1 << " ";
    }
    endl(cout);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}