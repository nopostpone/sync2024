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

    vector<bool> a(n / 3);
    int g1, b1;
    for (int i = 0; i < n / 3; i++) {
        a[i] = ask(3 * i, 3 * i + 1, 3 * i + 2);
        if (a[i]) {
            g1 = i * 3;
        } else {
            b1 = i * 3;
        }
    }

    auto judge = [&](int x) -> bool {
        assert(not good.empty() and not bad.empty());
        return ask(good[0], bad[0], x);
    };

    auto work = [&](int x) -> void {
        if (judge(x)) {
            good.push_back(x);
        } else {
            bad.push_back(x);
        }
    };

    int g2 = g1 + 1;
    int g3 = g1 + 2;
    int b2 = b1 + 1;
    int b3 = b1 + 2;

    bool A[] = {ask(g1, g2, b1), ask(g1, g2, b2)};
    if (A[0] and A[1]) {
        good = {g1, g2};
        if (ask(g1, b1, b2)) {
            bad.push_back(b3);
            if (judge(b1)) {
                good.push_back(b1);
                bad.push_back(b2);
            } else {
                good.push_back(b2);
                bad.push_back(b1);
            }
        } else {
            bad = {b1, b2};
            work(b3);
        }
        work(g3);
    } else if (not A[0] and not A[1]) {
        bad = {b1, b2};
        good.push_back(g3);
        if (judge(g1)) {
            good.push_back(g1);
            bad.push_back(g2);
        } else {
            good.push_back(g2);
            bad.push_back(g1);
        }
        work(b3);
    } else if (A[0]) {
        good.push_back(g3);
        good.push_back(b1);
        bad.push_back(b2);
        if (judge(g1)) {
            good.push_back(g1);
            bad.push_back(g2);
        } else {
            good.push_back(g2);
            bad.push_back(g1);
        }
        work(b3);
    } else {
        good.push_back(g3);
        good.push_back(b2);
        bad.push_back(b1);
        if (judge(g1)) {
            good.push_back(g1);
            bad.push_back(g2);
        } else {
            good.push_back(g2);
            bad.push_back(g1);
        }
        work(b3);
    }
    assert(bad.size() + good.size() == 6);

    // for (int i : good) {
    //     cerr << i + 1 << " \n"[i == good.back()];
    // }
    // for (int i : bad) {
    //     cerr << i + 1 << " \n"[i == bad.back()];
    // }

    for (int i = 0; i < n; i += 3) {
        if (i == g1 or i == b1) {
            continue;
        }
        if (a[i]) {
            if (ask(bad.front(), i + 1, i + 2)) {
                good.push_back(i + 1);
                good.push_back(i + 2);
                work(i);
            } else {
                good.push_back(i);
                if (judge(i + 2)) {
                    good.push_back(i + 2);
                    bad.push_back(i + 1);
                } else {
                    good.push_back(i + 1);
                    bad.push_back(i + 2);
                }
            }
        } else {
            if (not ask(good.front(), i + 1, i + 2)) {
                bad.push_back(i + 1);
                bad.push_back(i + 2);
                work(i);
            } else {
                bad.push_back(i);
                if (judge(i + 2)) {
                    good.push_back(i + 2);
                    bad.push_back(i + 1);
                } else {
                    good.push_back(i + 1);
                    bad.push_back(i + 2);
                }
            }
        }
    }
    assert(bad.size() + good.size() == n);

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