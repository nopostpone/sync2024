#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cout << fixed << setprecision(10);
    
    int n;
    cin >> n;

    while (n--) {
        int t;
        cin >> t;

        double num{}, den{};
        while (t--) {
            int x;
            cin >> x;
            num += x;
            den++;
        }
        cout << (den - num) / den << "\n";
    }
    
    return 0;
}