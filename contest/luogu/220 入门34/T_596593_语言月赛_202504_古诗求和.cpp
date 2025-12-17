#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<string> a;
    set<int> b;
    int cur = 0;

    int p = 0;
    while (true) {
        u32 q1 = s.find(',', p);
        u32 q2 = s.find('.', p);
        u32 q3 = s.find('!', p);
        u32 q4 = s.find('?', p);
        u32 q = min({q1, q2, q3, q4});
        string t = s.substr(p, q - p);
        p = q + 1;
        if ((int)q == -1) {
            break;
        }
        a.push_back(t);
        cur++;
        if (q != q1) {
            b.insert(cur);
        }
    }

    i64 sum = 0;
    int cnt = 0;
    for (int ii = 0; ii < a.size(); ii++)
    {
        auto t = a[ii];
        int f = -1;
        for (int i = 0; i < t.size(); i++) {
            if ('0' <= t[i] and t[i] <= '9') {
                f = i;
            } else if (f != -1) {
                cnt++;
                sum += t[i - 1] - '0';
                f = -1;
            }
            if (i == t.size() - 1 and f != -1) {
                cnt++;
                sum += t[i - 1] - '0';
                f = -1;

            }
        }

        if (b.contains(ii + 1)) {
            cout << cnt << " " << (sum % 2 ? "Odd" : "Even") << "\n";
            sum = 0;
            cnt = 0;
        }
    }

    return 0;
}