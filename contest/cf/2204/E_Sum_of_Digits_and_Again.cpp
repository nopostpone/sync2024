#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

string get(string s) {
    if (s.size() == 1) {
        return move(s);
    }

    int sum = 0;
    for (auto c : s) {
        sum += c - '0';
    }
    return move(s + get(to_string(sum)));
}

void solve() {
    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << s << "\n";
        return;
    }

    array<int, 10> cnt {};
    for (auto c : s) {
        cnt[c - '0']++;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += i * cnt[i];
    }

    for (int x = 1; x <= sum; x++) {
        auto tail = get(to_string(x));

        for (auto c : tail) {
            cnt[c - '0']--;
            sum -= c - '0';
        }
        bool valid = true;
        if (sum != x) {
            valid = false;
        }
        for (int i = 0; i < 10; i++) {
            if (cnt[i] < 0) {
                valid = false;
            }
        }
        if (count(cnt.begin() + 1, cnt.end(), 0) == 9) {
            valid = false;
        }

        if (valid) {
            for (int i = 1; i < 10; i++) {
                if (cnt[i]) {
                    cout << i;
                    cnt[i]--;
                    break;
                }
            }
            for (int i = 0; i < 10; i++) {
                while (cnt[i] != 0) {
                    cnt[i]--;
                    cout << i;
                }
            }
            cout << tail << "\n";
            return;
        } else {
            for (auto c : tail) {
                cnt[c - '0']++;
                sum += c - '0';
            }
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}