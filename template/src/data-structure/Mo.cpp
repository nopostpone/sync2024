{
    std::vector<std::array<int, 3>> ask(q);
    // ...
    std::ranges::sort(ask, [&](auto i, auto j) {
        if (i[0] / B != j[0] / B) {
            return i[0] < j[0];
        }
        return (i[0] / B) % 2 ? i[1] > j[1] : i[1] < j[1];
    });
    // ...
    // [l, r)
    int L = 0, R = 0;
    for (auto [l, r, i] : ask) {
        while (L > l) {
            add(--L);
        }
        while (R < r) {
            add(R++);
        }
        while (L < l) {
            del(L++);
        }
        while (R > r) {
            del(--R);
        }
        // ans[i] = ?
    }
}

// Mo With Modify
// B = n ^ (2 / 3)
{
    // ...
    std::vector<std::array<int, 4>> ask;
    std::vector<std::pair<int, int>> mod;
    for (int i = 0; i < m; i++) {
        char o;
        int x, y;
        std::cin >> o >> x >> y;
        x--;
        if (modify) {
            mod.emplace_back(x, y);
        } else {
            ask.push_back({x, y, (int)mod.size(), (int)ask.size()});
        }
    }
    std::ranges::sort(ask, [&](auto i, auto j) {
        if (i[0] / B != j[0] / B)
            return i[0] < j[0];
        if (i[1] / B != j[1] / B)
            return i[1] < j[1];
        return (i[1] / B) & 1 ? i[2] < j[2] : i[2] > j[2];
    });
    auto add = [&](int c) {
        // ...
    };
    auto del = [&](int c) {
        // ...
    };
    auto modify = [&](int p, int l, int r) {
        // if (l <= x and x < r) then del(ori) and add(cur)

        // first modify : x -> y
        // second modify : y -> x
        // using swap
    };
    // [l, r)
    int L = 0, R = 0, T = 0;
    for (auto [l, r, t, i] : que) {
        while (l < L) {
            add(a[--L]);
        }
        while (R < r) {
            add(a[R++]);
        }
        while (L < l) {
            del(a[L++]);
        }
        while (R > r) {
            del(a[--R]);
        }
        while (T < t) {
            modify(T++, l, r);
        }
        while (T > t) {
            modify(--T, l, r);
        }
        // ans[i] = ?
    }
}