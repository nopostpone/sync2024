template <typename T, class C = less<T>>
struct ST {
    const int n;
    const int logn;
    const C cmp;
    vector<vector<T>> jump;

    constexpr SparseTable(const std::vector<T> &a)
        : n{static_cast<int>(a.size())}, logn{__lg(n)}, cmp{}, jump(logn + 1) {

        jump[0] = a;

        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }

        for (int j = 0; j < logn; j++) {
            int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = min(jump[j][i], jump[j][i + (1 << j)], cmp);
            }
        }
    }
    // [l, r)
    constexpr T operator()(int l, int r) const {
        int layers = __lg(r - l);
        return min(jump[layers][l], jump[layers][r - (1 << layers)], cmp);
    }
};