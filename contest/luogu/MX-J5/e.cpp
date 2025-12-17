#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace QuickRead {
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline int getc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <typename T> void Cin(T &a) {
        T ans = 0;
        bool f = 0;
        char c = getc();
        for (; c < '0' || c > '9'; c = getc()) {
            if (c == '-') f = 1;
        }
        for (; c >= '0' && c <= '9'; c = getc()) {
            ans = ans * 10 + c - '0';
        }
        a = f ? -ans : ans;
    }
    template <typename T, typename... Args> void Cin(T &a, Args &...args) {
        Cin(a), Cin(args...);
    }
    template <typename T> void write(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
}

using namespace QuickRead;

struct Node {
    int x, y;
    ll val;
};
constexpr bool cmp0(const Node &a, const Node &b) {
    return a.val == b.val ? a.y - a.x < b.y - b.x : a.val > b.val;
}
constexpr bool cmp1(const Node &a, const Node &b) {
    return a.val == b.val ? a.y - a.x > b.y - b.x : a.val > b.val;
}

void solve() {
    int n;
    Cin(n);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        Cin(a[i]);
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<Node> s;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            if (pre[r] - pre[l - 1] > 0)
                s.push_back(Node{l - 1, r - 1, pre[r] - pre[l - 1]});
        }
    }
    
    vector<int> fff;

    ranges::sort(s, cmp0);
    
    vector<ll> ans(n, 0);
    int num = 0;
    for (auto [x, y, val] : s) {
        
        num++;
        ans[num - 1] = val;
    }
    for (int i = 0; i < n; i++) {   
        if (i > 0) {
            ans[i] += ans[i - 1];
        }
        write(ans[i]);
        putchar(' ');
    }
    putchar('\n');

    ans.assign(n, 0);

    ranges::sort(s, cmp1);
    num = 0;
    for (auto [x, y, val] : s) {
        
        num++;
        ans[num - 1] = val;
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            ans[i] += ans[i - 1];
        }
        write(ans[i]);
        putchar(' ');
    }
    putchar('\n');
    
    
}

int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (Cin(T); T--;) {
        solve();
    }

    return 0;
}