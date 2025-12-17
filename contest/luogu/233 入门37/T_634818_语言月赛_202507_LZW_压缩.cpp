#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, _;
    cin >> n >> k >> _;

    unordered_map<string, int> D;
    int tot = 0;

    vector<string> ans;

    for (; tot < k; tot++) {
        string d;
        cin >> d;
        D[d] = tot;
        ans.push_back(d);
    }
    
    string s;
    cin >> s;

    string cur{};
    for (auto c : s) {
        string nxt = cur + c;
        if (D.contains(nxt)) {
            cur = nxt;
            continue;
        }
        
        D[nxt] = tot++;
        ans.push_back(nxt);
        cout << D[cur] + 1 << " ";
        cur = string{c};
    }
    cout << D[cur] + 1 << "\n";

    cout << tot << "\n";
    for (auto str : ans) {
        cout << str << "\n";
    }

    return 0;
}