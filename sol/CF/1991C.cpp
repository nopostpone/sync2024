#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

bool check(const vector<int> &A) {
    for (auto i = A.begin(); i != A.end(); i++) {
        if (*i) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b;
    while (!check(a) and b.size() < 45)  {
        int x = (*min_element(a.begin(), a.end()) + *max_element(a.begin(), a.end())) / 2;
        b.push_back(x);
        for (auto &i : a) {
            i -= x;
            if (i < 0) {
                i = -i;
            }
        }
    }
    if (b.size() > 40) {
        cout << -1 << "\n";
    } else {
        cout << b.size() << endl;
        for (auto i : b)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}