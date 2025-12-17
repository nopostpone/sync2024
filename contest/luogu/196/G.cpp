#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string s;
    cin >> s;

    vector<int> a;
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 6) == "friend") {
            a.push_back(i);
        }
    }
    int cnt = a.size();
    for (int i = 1; i < a.size(); i++) {
        if (a[i] - a[i - 1] < 9) {
            cnt--;
            i++;
        }
    }
    cout << cnt << endl;

    return 0;
}