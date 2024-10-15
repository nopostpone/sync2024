template <class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const int logn;

    const Cmp cmp = Cmp();
    std::vector<std::vector<T>> jump;

    constexpr RMQ(const std::vector<T> &a)
        : n{a.size()}, logn{std::__lg(n)}, jump(logn + 1) {

        jump[0] = a;

        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }

        for (int j = 0; j < logn; j++) {
            const int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = std::min(jump[j][i], jump[j][i + (1 << j)], cmp);
            }
        }
    }

    constexpr T operator()(int l, int r) const {
        int log = std::__lg(r - l);
        return std::min(jump[log][l], jump[log][r - (1 << log)], cmp);
    }
};