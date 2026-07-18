#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

std::string vowels = "aeiou";

bool check(std::string s) {
    if (s.size() != 8) {
        return false;
    }
    for (int i = 0; i < 8; i += 2) {
        if (rgs::binary_search(vowels, s[i])) {
            return false;
        }
    }
    for (int i = 1; i < 8; i += 2) {
        if (not rgs::binary_search(vowels, s[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int _ = 0; _ < n; _++) {
        std::string s;
        std::cin >> s;

        std::cout << (check(s) ? "Suspected Virus" : "Well-Being") << "\n";
    }
}