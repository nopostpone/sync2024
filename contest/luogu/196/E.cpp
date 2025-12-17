#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, t;
    cin >> n >> t;

    int g = std::pow(10, t);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> st;
    for (auto i : a) {
        int j = i % g;
        st.insert(j);
    }
    cout << st.size();
    
    return 0;
}