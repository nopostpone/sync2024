#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;

    for (auto c : s) {
        if ('A' <= c and c <= 'Z') {
            std::cout << c;
        }
    }

    return 0;
}