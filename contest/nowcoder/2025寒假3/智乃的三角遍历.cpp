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

    vector<int> st(n + 1);
    st[0] = 1;
    for (int i = 1; i <= n; i++) {
        st[i] = st[i - 1] + i + 1;
    }

    cout << "Yes\n";

    vector<int> res;

    auto mov = [&](int x, int y) {
        if (x > y) {
            for (int i = x; i >= y; i--) {
                res.push_back(i);
            }
        } else {
            for (int i = x; i <= y; i++) {
                res.push_back(i);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (not i) {
            res.push_back(1);
            continue;
        }
        if (i % 2 == 0) {
            mov(st[i], st[i - 1] + 1);
        } else {
            mov(st[i - 1] + 1, st[i]);
        }
    }
    if (n % 2 == 0) {
        mov(st.back(), st[n - 1] + 1);
    } else {
        mov(st[n - 1] + 1, st.back());
    }

    auto movl = [&](int dep) {
        int now = st[dep];
        int up = st[dep - 1];
        while (now > st[dep - 1] + 2) {
            res.push_back(up);
            now--;
            up--;
            res.push_back(now);
        }
        res.push_back(up);
    };
    auto movr = [&](int dep) {
        int now = st[dep - 1] + 1;
        int up = st[dep - 2] + 1;
        while (now < st[dep] - 1) {
            res.push_back(up);
            now++;
            up++;
            res.push_back(now);
        }
        res.push_back(up);
    };

    for (int i = n; i; i--) {
        if (i % 2) {
            movl(i);
        } else {
            movr(i);
        }
    }

    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}