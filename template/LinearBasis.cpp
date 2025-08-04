template <class U>
struct LinearBasis {
    int n, m;
    std::vector<U> a, b;
    LinearBasis() : n{0}, m{0} {}
    LinearBasis(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        this->m = 0;
        a.assign(n, {});
        b.assign(n, {});
    }
    void insert(U x) {
        U y = x;
        for (int i = n - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (a[i] == U()) {
                    a[i] = x;
                    b[i] = y;
                    m++;
                    return;
                }
                x ^= a[i];
            }
        }
    }
    bool contains(U x) {
        for (int i = n - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (a[i] == U()) {
                    return false;
                }
                x ^= a[i];
            }
        }
        return true;
    }
    int size() {
        return m;
    }
    int rank() {
        return n - m;
    }
    U &operator[](int x) {
        return b[x];
    }
    const U &operator[](int x) const {
        return b[x];
    }
};
using L32 = LinearBasis<u32>;
using L64 = LinearBasis<u64>;