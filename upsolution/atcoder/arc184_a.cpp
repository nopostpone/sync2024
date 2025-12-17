#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ask(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    int r;
    cin >> r;
    assert(r != -1);
    return r == 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> res;

    constexpr int len = 11;
    int te = -1;

    vector<pair<vector<int>, vector<int>>> f;

    for (int i = 0; i < 90 * len; i += len) {
        vector<int> same, diff;
        same.push_back(i);
        for (int j = 1; j < len; j++) {
            if (ask(i, i + j)) {
                same.push_back(i + j);
            } else {
                diff.push_back(i + j);
            }
        }
        if (same.size() == len) {
            te = same.front();
        } else {
            f.push_back({same, diff});
        }
    }

    for (auto &&[same, diff] : f) {
        if (ask(same.front(), te)) {
            for (auto i : diff) {
                res.push_back(i);
            }
        } else {
            for (auto i : same) {
                res.push_back(i);
            }
        }
    }
    if (res.empty()) {
        for (int i = 990; i < 1000; i++) {
            res.push_back(i);
        }
    } else {
        for (int i = 990; i < 1000 and res.size() <= 10; i++) {
            if (not ask(i, te)) {
                res.push_back(i);
            }
        }
    }

    cout << "! ";
    for (auto i : res) {
        cout << i + 1 << " \n"[i == res.back()];
    }

    return 0;
}