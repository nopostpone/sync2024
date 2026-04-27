#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x0, y0;
    cin >> n >> m >> x0 >> y0;
    x0--;
    y0--;
    
    auto encode = [&](int x, int y) {
        return x * m + y;
    };
    auto decode = [&](int t) {
        return pair{t / m, t % m};
    };
    
    vector<int> seq;
    string op;

    int x = 0, y = 0;
    auto moveUp = [&](int step) {
        for (int i = 0; i < step; i++) {
            seq.push_back(encode(x--, y));
            op += 'U';
        }
    };
    auto moveDown = [&](int step) {
        for (int i = 0; i < step; i++) {
            seq.push_back(encode(x++, y));
            op += 'D';
        }
    };
    auto moveLeft = [&](int step) {
        for (int i = 0; i < step; i++) {
            seq.push_back(encode(x, y--));
            op += 'L';
        }
    };
    auto moveRight = [&](int step) {
        for (int i = 0; i < step; i++) {
            seq.push_back(encode(x, y++));
            op += 'R';
        }
    };

    if (m % 2 == 0) {
        moveRight(m - 1);
        moveDown(n - 1);
        moveLeft(1);
        while (y > 0) {
            moveUp(n - 2);
            moveLeft(1);
            moveDown(n - 2);
            moveLeft(1);
        }
        moveUp(n - 1);
    } else if (n % 2 == 0) {
        moveDown(n - 1);
        moveRight(m - 1);
        moveUp(1);
        while (x > 0) {
            moveLeft(m - 2);
            moveUp(1);
            moveRight(m - 2);
            moveUp(1);
        }
        moveLeft(m - 1);
    } else {
        moveRight(m - 1);
        moveDown(n - 1);
        moveLeft(2);
        moveUp(1);
        while (x > 1) {
            moveRight(1);
            moveUp(1);
            moveLeft(1);
            moveUp(1);
        }
        while (y > 0) {
            moveLeft(1);
            moveDown(n - 2);
            moveLeft(1);
            moveUp(n - 2);
        }
        moveUp(1);
    }

    int tot = seq.size();

    vector<int> f(n * m);
    f[encode(1, m - 2)] = -1;
    for (int i = 0; i < tot; i++) {
        f[seq[i]] = i;
    }
    int r1 = f[encode(0, m - 2)];
    int r2 = f[encode(1, m - 1)];

    int p = f[encode(x0, y0)];

    auto get = [&](int s, int e) {
        if (e >= s) {
            return op.substr(s, e - s);
        } else {
            return op.substr(s) + op.substr(0, e);
        }
    };
    for (int _ = 0; _ < n * m - 1; _++) {
        cin >> x >> y;
        x--;
        y--;

        int q = f[encode(x, y)];
        string ans;

        if (p == -1) {
            ans += 'R';
            p = r2;
        }
        if (q == -1) {
            ans += get(p, r1) + 'D';
        } else {
            ans += get(p, q);
        }
        p = q;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}