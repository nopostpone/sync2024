#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int P = 2999999;
constexpr int half = 1500000;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = (i64)a * a % P) {
        if (b & 1) {
            res = (i64)res * a % P;
        }
    }
    return res;
}
void add(int &x, int y) {
    x += y;
    if (x >= P) {
        x -= P;
    }
}

int query(int p, int q) {
    int g = gcd(p, q);
    p /= g;
    q /= g;
    cout << "? " << p << " " << q << endl;

    int num = 0, den = 0;
    {
        string s;
        cin >> s;

        for (auto c : s) {
            num = num * 10 + (c - '0');
            num %= P;
        }
    }
    {
        string s;
        cin >> s;

        for (auto c : s) {
            den = den * 10 + (c - '0');
            den %= P;
        }
    }

    return i64(num) * power(den, P - 2) % P;
}

struct Point {
    int x {};
    int y {};
};

void solve() {
    int n;
    cin >> n;

    vector<Point> p(n);
    for (auto &[x, y] : p) {
        cin >> x >> y;
    }

    sort(p.begin(), p.end(), [](auto a, auto b) {
        return a.x < b.x;
    });

    bool flag {};
    for (int i = 1; i < n; i++) {
        if (p[i].x == p[i - 1].x) {
            flag = true;
        }
    }

    int ans = 0;
    if (flag) {
        int lst = p[0].x;
        for (int i = 0; i < n; i++) {
            if (p[i].x == lst) {
                continue;
            }
            auto res = query(lst + p[i].x, 2);
            res = (i64)res * (p[i].x - lst) % P;
            add(ans, res);
            lst = p[i].x;
        }
    } else {
        vector<int> b(n);
        b[0] = b[n - 1] = 0;
        for (int i = 1; i < n - 1; i++) {
            b[i] = query(p[i].x, 1);
        }

        for (int i = 1; i < n; i++) {
            int res = i64(b[i - 1] + b[i]) * (p[i].x - p[i - 1].x) * half % P;
            add(ans, res);
        }
    }

    int num = 0, den = 0;
    if (ans < half) {
        num = ans;
        den = 1;
    } else {
        num = (ans - half) * 2 + 1;
        den = 2;
    }
    cout << "! " << num << " " << den << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

/*
1
4
0 0
1 3
1 1
3 0

1
3
0 0
1000 999
999 1000
*/