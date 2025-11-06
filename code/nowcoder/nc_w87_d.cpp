// https://ac.nowcoder.com/acm/problem/263831
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    stack<int> tl, tr;
    for (int i = 0; s[i] != 'I'; i++) {
        tl.push(i);
    }
    for (int i = n - 1; s[i] != 'I'; i--) {
        tr.push(i);
    }

    while (m--) {
        string op;
        cin >> op;

        int l = tl.empty() ? -1 : tl.top();
        int r = tr.empty() ? -1 : tr.top();

        if (op == "backspace") {
            if (l == -1) {
                continue;
            }
            if (r != -1) {
                if (s[l] == '(' and s[r] == ')') {
                    tr.pop();
                }
            }
            tl.pop();
        } else if (op == "delete") {
            if (r == -1) {
                continue;
            }
            tr.pop();
        } else if (op == "<-") {
            if (l == -1) {
                continue;
            }
            tr.push(l);
            tl.pop();
        } else {
            if (r == -1) {
                continue;
            }
            tl.push(r);
            tr.pop();
        }
    }


    string res;
    while (!tl.empty()) {
        res.push_back(s[tl.top()]);
        tl.pop();
    }
    reverse(res.begin(), res.end());

    res.push_back('I');
    
    while (!tr.empty()) {
        res.push_back(s[tr.top()]);
        tr.pop();
    }
    
    cout << res;

    return 0;
}