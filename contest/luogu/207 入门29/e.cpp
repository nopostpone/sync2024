#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int x, n;
    cin >> x >> n;

    vector<int> res(6);
    for (int i = 0; i < n; i++) {
        set<int> s;
        for (int j = 0; j < 5; j++) {
            int z;
            cin >> z;
            s.insert(z);
        }

        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (x >= *it) {
                res[*it]++;
                x -= (*it);
                break;
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        cout << res[i] << " \n"[i == 5];
    }
    cout << x << endl;
    
    return 0;
}