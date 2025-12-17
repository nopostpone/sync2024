#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

map<array<int, 9>, int> f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto op1 = [&](array<int, 9> a, int x) {
        x *= 3;
        int tem = a[x + 2];
        a[x + 2] = a[x + 1];
        a[x + 1] = a[x];
        a[x] = tem;
        return a;
    };
    auto op2 = [&](array<int, 9> a, int x) {
        int tem = a[x + 6];
        a[x + 6] = a[x + 3];
        a[x + 3] = a[x];
        a[x] = tem;
        return a;
    };
    auto op3 = [&](array<int, 9> a) {
        int tem = a[3];
        a[3] = a[7];
        a[7] = a[5];
        a[5] = a[1];
        a[1] = tem;
        tem = a[0];
        a[0] = a[6];
        a[6] = a[8];
        a[8] = a[2];
        a[2] = tem;
        return a;
    };

    queue<array<int, 9>> q;
    q.push(array{0, 1, 2, 3, 4, 5, 6, 7, 8});
    f[{0, 1, 2, 3, 4, 5, 6, 7, 8}] = 0;
    while (not q.empty()) {
        auto a = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            auto na = op1(a, i);
            if (not f.contains(na)) {
                f[na] = f[a] + 1;
                q.push(na);
            }
        }

        for (int i = 0; i < 3; i++) {
            auto na = op2(a, i);
            if (not f.contains(na)) {
                f[na] = f[a] + 1;
                q.push(na);
            }
        }

        auto na = op3(a);
        if (not f.contains(na)) {
            f[na] = f[a] + 1;
            q.push(na);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        array<int, 9> a, b;

        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < 3; j++) {
                a[i * 3 + j] = s[j] - '0';
            }
        }
        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < 3; j++) {
                b[i * 3 + j] = s[j] - '0';
            }
        }
        
        array<int, 9> p{};
        for (int i = 0; i < 9; i++) {
            p[a[i] - 1] = i;
        }
        for (int i = 0; i < 9; i++) {
            b[i] = p[b[i] - 1];
        }

        if (f.contains(b)) {
            cout << f[b] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}