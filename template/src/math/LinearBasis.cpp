// a : base
// k : dimension
{
    auto insert = [&](int x) {
        for (int d = k - 1; d >= 0 and x != 0; d--) {
            if (x >> d & 1) {
                if (a[d] == 0) {
                    a[d] = x;
                }
                x ^= a[d];
            }
        }
    };
    // ...
    int ans = 0;
    for (int d = k - 1; d >= 0; d--) {
        ans = max(ans, ans ^ a[d]);
    }
}
// t : time stamp
{
    auto insert = [&](int x, int i) {
        for (int d = k - 1; d >= 0; d--) {
            if (x >> d & 1) {
                if (i > t[d]) {
                    swap(i, t[d]);
                    swap(x, a[d]);
                }
                x ^= a[d];
            }
        }
    };
    auto query = [&](int i) {
        int res = 0;
        for (int d = k - 1; d >= 0; d--) {
            if (t[d] >= i) {
                res = max(res, res ^ a[d]);
            }
        }
        return res;
    };
}