#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> q;
    q.push(16);
    set<int> s;
    s.insert(16);
    while (not q.empty()) {
        int x = q.top();
        // cerr << x << endl;

        for (int i = x / 2; i > 0; i--) {
            int j = x - i;
            if (i == j or s.contains(i) or s.contains(j)) {
                continue;
            }
            s.erase(x);
            q.push(i);
            q.push(j);
            s.insert(i);
            s.insert(j);
            break;
        }
        if (s.contains(x)) {
            break;
        }
        q.pop();
    }
    while (not q.empty()) {
        cerr << q.top() << endl;
        q.pop();
    }

    return 0;
}