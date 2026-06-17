#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

using i64 = long long;
using u64 = unsigned long long;

namespace rgs = std::ranges;

std::vector<std::string> all;

int query(const std::string &s) {
    std::cout << "? " << s << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}
void answer(const std::string &s) {
    std::cout << "! " << s << std::endl;
}

int match(const std::string &a, const std::string &b) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += a[i] == b[i];
    }
    return res;
}

void solve() {
    std::array<int, 10> cnt {};

    for (int i = 0; i < 9; i++) {
        std::string si(4, i + '0');
        int res = query(si);
        if (res == 4) {
            answer(si);
            return;
        }
        cnt[i] = res;
    }
    cnt[9] = 4 - std::accumulate(cnt.begin(), cnt.end(), 0);

    std::string base;
    for (int i = 0; i < 10; i++) {
        base += std::string(cnt[i], '0' + i);
    }

    std::vector<std::string> cand;
    do {
        cand.push_back(base);
    } while (std::next_permutation(base.begin(), base.end()));

    auto eval = [&](const std::string &s) {
        std::array<int, 5> cnt {};
        for (auto &t : cand) {
            cnt[match(s, t)]++;
        }

        int cur = rgs::max(cnt);
        int sumeq = 0;
        std::for_each(cnt.begin(), cnt.end(), [&](int x) {
            sumeq += x * x;
        });

        return std::pair(cur, sumeq);
    };

    while (true) {
        if (cand.size() == 1) {
            answer(cand.front());
            return;
        }

        int bestMax = 1e9, bestSumeq = 1e9;
        std::string guess;

        for (auto &t : cand) {
            auto [max, sumeq] = eval(t);

            if (max < bestMax or (max == bestMax and sumeq < bestSumeq)) {
                bestMax = max;
                bestSumeq = sumeq;

                guess = t;
            }
        }

        if (bestMax > 1) {
            for (const auto &t : all) {
                auto [max, sumeq] = eval(t);

                if (max < bestMax or (max == bestMax and sumeq < bestSumeq)) {
                    bestMax = max;
                    bestSumeq = sumeq;

                    guess = t;
                }
                if (bestMax == 1) {
                    break;
                }
            }
        }

        int res = query(guess);
        std::vector<std::string> ncand;
        for (const auto &t : cand) {
            if (match(t, guess) == res) {
                ncand.push_back(t);
            }
        }

        cand = std::move(ncand);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s(4, '0');
    [&](this auto &&self, int dep) -> void {
        if (dep == 4) {
            all.push_back(s);
            return;
        }

        for (int i = 0; i < 10; i++) {
            s[dep] = i + '0';
            self(dep + 1);
        }
    } (0);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}