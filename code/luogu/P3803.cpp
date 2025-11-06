#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Complex {
    double real;
    double imag;

    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}
};

constexpr Complex operator+(Complex a, Complex b) {
    return {a.real + b.real, a.imag + b.imag};
}
constexpr Complex operator-(Complex a, Complex b) {
    return {a.real - b.real, a.imag - b.imag};
}
constexpr Complex operator*(Complex a, Complex b) {
    return {a.real * b.real - a.imag * b.imag,
            a.real * b.imag + a.imag * b.real};
}

const double PI = acos(-1);

void fft(vector<Complex> &f, int type) {
    int n = f.size();
    if (n == 1) {
        return;
    }

    vector<Complex> g(n / 2), h(n / 2);
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            h[i / 2] = f[i];
        } else {
            g[i / 2] = f[i];
        }
    }

    fft(g, type);
    fft(h, type);

    Complex cur(1, 0);
    Complex step(cos(2 * PI / n), -type * sin(2 * PI / n));
    for (int i = 0; i < n / 2; i++) {
        f[i] = g[i] + cur * h[i];
        f[i + n / 2] = g[i] - cur * h[i];
        cur = cur * step;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Complex> f(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> f[i].real;
    }
    vector<Complex> g(m + 1);
    for (int i = 0; i <= m; i++) {
        cin >> g[i].real;
    }

    int t = 1;
    while (t <= n + m) {
        t *= 2;
    }
    f.resize(t);
    g.resize(t);


    fft(f, 1);
    fft(g, 1);

    vector<Complex> h(t);
    for (int i = 0; i < t; i++) {
        h[i] = f[i] * g[i];
    }

    fft(h, -1);
    for (int i = 0; i < n + m + 1; i++) {
        cout << (i64)round(h[i].real / t) << " \n"[i == t - 1];
    }

    return 0;
}