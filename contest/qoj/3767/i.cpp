#include <bits/stdc++.h>

namespace rgs = std::ranges;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            std::cin >> x[i] >> y[i];
        }

        std::vector<int> ord(n);
        rgs::iota(ord, 0);

        int p = *max_element(ord.begin(), ord.end(), [&](int i, int j) {
            return (x[i] < x[j]) or (x[i] == x[j] and y[i] < y[j]);
        });

        std::cout << x[p] << " " << y[p] << "\n";

    }
}

/*
3
3
5 11
5 9
3 12
2
1 0
0 1
2
0 0
0 0
*/