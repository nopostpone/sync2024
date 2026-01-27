#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
    
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        queue<int> q(a.begin(), a.end());
        for (int t = 0; t < n - 1; t++) {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
    
            cout << max(x, y) << "\n";
            q.push(min(x, y));
        }
    }

}