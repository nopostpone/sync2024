#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b;
    for (auto x : a) {
        if (x <= 15) {
            b.push_back(x);
        }
    }
    for (auto x : a) {
        if (x > 15) {
            b.push_back(x);
        }
    }
    for (auto x : b) {
        cout << x << " ";
    }

    return 0;
}