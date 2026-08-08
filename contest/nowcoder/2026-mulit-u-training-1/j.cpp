#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

enum type {
    highcard,
    pair,
    two_pairs,
    three_of_a_kind,
    straight,
    flush,
    full_house,
    four_of_a_kind,
    straight_flush,
    royal_flush
};
using hand = std::array<std::array<int, 2>, 5>;

hand Royal[4];
bool isRoyal(hand a) {
    // a is sorted
    for (int i = 0; i < 4; i++) {
        if (a == Royal[i]) {
            return true;
        }
    }
    return false;
}

bool isStraight(hand &a) {
    // a is sorted
    static int sp[5] {2, 3, 4, 5, 14};
    bool same = true;
    for (int i = 0; i < 5; i++) {
        same &= (a[i][0] == sp[i]);
    }
    if (same) {
        for (int i = 0; i < 5; i++) {
            a[i][0] = i + 1;
        }
        return true;
    }
    for (int i = 1; i < 5; i++) {
        if (a[i][0] - a[i - 1][0] != 1) {
            return false;
        }
    }
    return true;
}
bool isFlush(hand a) {
    for (int i = 1; i < 5; i++) {
        if (a[i][1] != a[i - 1][1]) {
            return false;
        }
    }
    return true;
}

type getType(hand &a) {
    std::array<int, 15> c {};
    for (int i = 0; i < 5; i++) {
        c[a[i][0]]++;
    }
    rgs::sort(c, std::greater());
    rgs::sort(a);

    if (isRoyal(a)) {
        return royal_flush;
    }
    bool fl = isFlush(a);
    bool st = isStraight(a);

    if (fl and st) {
        return straight_flush;
    }
    if (c[0] >= 4) {
        return four_of_a_kind;
    }
    if (c[0] == 3 and c[1] == 2) {
        return full_house;
    }
    if (fl) {
        return flush;
    }
    if (st) {
        return straight;
    }
    if (c[0] == 3) {
        return three_of_a_kind;
    }
    if (c[0] == 2 and c[1] == 2) {
        return two_pairs;
    }
    if (c[0] == 2 and c[1] != 2) {
        return pair;
    }
    return highcard;
}

u64 getScore(hand a) {
    u64 res = getType(a);
    std::array<int, 15> cnt {};
    for (int i = 0; i < 5; i++) {
        cnt[a[i][0]]++;
    }
    rgs::sort(a, [&](auto x, auto y) {
        return cnt[x[0]] > cnt[y[0]] or (cnt[x[0]] == cnt[y[0]] and x[0] > y[0]);
    });

    for (int i = 0; i < 5; i++) {
        res = (res << 4) | a[i][0];
    }
    return res;
}

int compare(hand a, hand b) {
    auto sa = getScore(a);
    auto sb = getScore(b);

    if (sa == sb) {
        return 0;
    }
    return (sa > sb ? 1 : -1);
}
constexpr int rank2num(char c) {
    if (c == 'A') {
        return 14;
    }
    if (c == 'J') {
        return 11;
    }
    if (c == 'Q') {
        return 12;
    }
    if (c == 'K') {
        return 13;
    }
    if (c == 'T') {
        return 10;
    }

    return c - '0';
}

constexpr std::string Suit = "CDSH";

void solve() {
    hand c, p;
    for (int i = 0; i < 4; i++) {
        char rank, suit;
        std::cin >> rank >> suit;
        c[i] = {rank2num(rank), suit};
    }
    for (int i = 0; i < 4; i++) {
        char rank, suit;
        std::cin >> rank >> suit;
        p[i] = {rank2num(rank), suit};
    }
    
    std::set<std::array<int, 2>> vis;
    for (int i = 0; i < 4; i++) {
        vis.insert(c[i]);
        vis.insert(p[i]);
    }

    int wincnt = 0;
    for (int i = 2; i <= 14; i++) {
        for (int j : Suit) {
            if (vis.contains({i, j})) {
                continue;
            }
            p[4] = {i, j};
            vis.insert(p[4]);
            
            bool win = false, draw = false;

            for (int ni = 2; ni <= 14 and not win; ni++) {
                for (int nj : Suit) {
                    if (vis.contains({ni, nj})) {
                        continue;
                    }
                    c[4] = {ni, nj};
                    int res = compare(c, p);
                    if (res == 1) {
                        win = true;
                        break;
                    } else if (res == 0) {
                        draw = true;
                    }
                }
            }
            if (not win and not draw) {
                std::cout << "GeiWoCaPiXie\n";
                return;
            } else if (win) {
                wincnt++;
            }

            vis.erase(p[4]);
        }
    }

    if (wincnt == 44) {
        std::cout << "WoYaoYanPai\n";
    } else {
        std::cout << "PaiMeiYouWenTi\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    {
        int p = 0;
        for (int j : Suit) {
            for (int i = 10; i <= 14; i++) {
                Royal[p][i - 10] = {i, j};
            }
            p++;
        }
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}