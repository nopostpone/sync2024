#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;

    {
        set<int> st;
        for (int i = n - 1; ~i; i--) {
            if (st.contains(s[i])) {
                ans = max(ans, i + 1);
                break;
            }
            st.insert(s[i]);
        }
    }
    {
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (st.contains(s[i])) {
                ans = max(ans, n - i);
                break;
            }
            st.insert(s[i]);
        }
    }
    cout << ans << "\n";

    return 0;
}