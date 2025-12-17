#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<vector<int>> adj(n);
    int m = 0;

    vector<int> stka, stkb;
    for (int i = 0; i < n; i++) {
        while (not stka.empty() and stka.back() <= a[i]) {
            stka.pop_back();
        }
        while (not stkb.empty() and stkb.back() >= b[i]) {
            stkb.pop_back();
        }
        if (not stka.empty()) {
            m++;
            adj[stka.back()].push_back(a[i]);
        }
        if (not stkb.empty()) {
            m++;
            adj[stkb.back()].push_back(b[i]);
        }
        stka.push_back(a[i]);
        stkb.push_back(b[i]);
    }

    vector<int> in(n);
    for (int x = 0; x < n; x++) {
        for (auto y : adj[x]) {
            in[y]++;
        }
    }

    set<int> sa, sb;
    for (int x = 0; x < n; x++) {
        if (in[x] == 0) {
            sa.insert(x);
            sb.insert(x);
        }
    }
    
    vector<int> na(n, -1), nb(n, -1);

    [&](auto in) {
        for (int i = 0; i < n; i++) {
            if (sa.empty()) {
                break;
            }
            int x = *sa.begin();
            sa.erase(x);
            na[i] = x;
            for (auto y : adj[x]) {
                in[y]--;
                if (in[y] == 0) {
                    sa.insert(y);
                }
            }
        }
    } (in);

    for (int i = 0; i < n; i++) {
        if (sb.empty()) {
            break;
        }
        int x = *sb.rbegin();
        sb.erase(x);
        nb[i] = x;
        for (auto y : adj[x]) {
            in[y]--;
            if (in[y] == 0) {
                sb.insert(y);
            }
        }
    }

    bool valid = a == na and b == nb;
    if (not valid) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << m << "\n";
        for (int x = 0; x < n; x++) {
            for (auto y : adj[x]) {
                cout << x + 1 << " " << y + 1 << "\n";
            }
        }
    }
}