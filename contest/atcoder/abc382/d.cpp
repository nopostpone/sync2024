#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    int x = (n - 1) * 10;
    int d = m - x;

    vector<int> a;  
    vector<vector<int>> b;
    auto dfs = [&](auto &&self) -> void {
        if (a.size() == n) {
            b.push_back(a);
            return;
        }
        if (a.empty()) {
            for (int i = 1; i <= d; i++) {
                a.push_back(i);
                self(self);
                a.pop_back();
            }
        } else {
            for (int i = 0; 10 + a.back() + i <= 10 * a.size() + d; i++) {
                a.push_back(10 + a.back() + i);
                self(self);
                a.pop_back();
            }
        }

    };
    dfs(dfs);    

    cout << b.size() << "\n";
    for (auto &&v : b) {
        for (auto &&i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}