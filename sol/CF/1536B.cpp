#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

string s;
vector<string> res;
char lt[30];

void dfs() {
}

void solve() {
    int n;
    cin >> n;
    cin >> s;
    for (char i = 'a'; i <= 'z'; i++) {
        if (s.find(i) == string::npos) {
            string tmp = {};
            tmp.push_back(i);
            res.push_back(tmp);
            return;
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            string tmp;
            tmp.push_back(i);
            tmp.push_back(j);
            if(s.find(tmp) == string::npos) {
                res.push_back(tmp);
                return;
            }
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                string tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(k);
                if (s.find(tmp) == string::npos) {
                    res.push_back(tmp);
                    return;
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    for (int i = 1; i <= 26; i++) {
        lt[i] = 'a' + i - 1;
    }
    while (_--)
        solve();
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}