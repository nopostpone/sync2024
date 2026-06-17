#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

namespace rgs = std::ranges;

constexpr std::string C[] {
    "9",
    "19",
    "109",
    "1009",
    "10009",
    "100009",
    "1000009",
    "10000009",
    "100000009",
};

void solve() {
    int l, r;
    std::cin >> l >> r;
    r++;

    if (r - l < 10) {
        std::vector<std::pair<char, std::string>> cond;
        for (int i = l; i < r; i++) {
            auto s = std::to_string(i);
            cond.emplace_back(rgs::max(s), s);
        }
        auto it = max_element(cond.begin(), cond.end(), [&](auto u, auto v) {
            return u.first < v.first or (u.first == v.first and u.second > v.second);
        });

        std::cout << it->first << " " << it->second << "\n";
        return;
    }


    auto sl = std::to_string(l);
    std::string si;
    for (int i = 0; i < 10; i++) {
        si = std::to_string(l + i);
        if (si.size() != sl.size()) {
            break;
        }
        if (si.contains('9')) {
            break;
        }
    }

    std::string s = si;
    for (auto t : C) {
        if (atoi(t.data()) < l or atoi(t.data()) >= r) {
            continue;
        }
        if (not s.contains('9') or t < s) {
            s = t;
        }
    }

    std::cout << 9 << " " << s << "\n";

}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}