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
    for (int i = 0; i < n; i += 3) {
        a[i / 3] = ask(i, i + 1, i + 2);
        if (a[i / 3]) {
            g1 = i;
        } else {
            b1 = i;
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

    auto work2 = [&](int x, int y) -> void {
        if (judge(x)) {
            good.push_back(x);
            bad.push_back(y);
        } else {
            good.push_back(y);
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
            work2(b1, b2);
        } else {
            bad = {b1, b2};
            work(b3);
        }
        work(g3);
    } else if (not A[0] and not A[1]) {
        bad = {b1, b2};
        good.push_back(g3);
        work2(g1, g2);
        work(b3);
    } else if (A[0]) {
        good = {g3, b1};
        bad = {b2, b3};
        work2(g1, g2);
    } else {
        good = {g3, b2};
        bad = {b1, b3};
        work2(g1, g2);
    }

    for (int i = 0; i < n; i += 3) {
        if (i == g1 or i == b1) {
            continue;
        }
        if (a[i / 3]) {
            if (ask(bad.front(), i + 1, i + 2)) {
                good.push_back(i + 1);
                good.push_back(i + 2);
                work(i);
            } else {
                good.push_back(i);
                work2(i + 1, i + 2);
            }
        } else {
            if (not ask(good.front(), i + 1, i + 2)) {
                bad.push_back(i + 1);
                bad.push_back(i + 2);
                work(i);
            } else {
                bad.push_back(i);
                work2(i + 1, i + 2);
            }
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