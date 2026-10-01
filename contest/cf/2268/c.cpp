// #include <bits/stdc++.h>

// using u32 = unsigned;
// using i64 = long long;
// using u64 = unsigned long long;

// using i128 = __int128;
// using u128 = unsigned __int128;

// namespace rgs = std::ranges;

// void solve() {
//     int n;
//     std::cin >> n;

//     std::vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         std::cin >> a[i];
//     }


// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int t;
//     std::cin >> t;

//     while (t--) {
//         solve();
//     }
// }




#include <bits/stdc++.h>
using namespace std;

constexpr int B = 18;
constexpr int N = 200000 + 5;
constexpr int MAXT = N * (B + 1) + 5;

struct Node {
    int ch[2];
    int cnt;
} tr[MAXT];

struct State {
    int r, l;
};

int root[N], pre[N];
int L[N], R[N], st[N];
State cur[1 << 17], nxt[1 << 17];

int query(int x, int ql, int qr, int mask) {
    if (ql > qr || mask == 0) return 0;

    int hi = 31 - __builtin_clz(mask);
    int lo = __builtin_ctz(mask);

    int nr = root[qr + 1];
    int nl = root[ql];

    // 高于 mask 最高位的部分一定相同
    for (int b = B - 1; b > hi; --b) {
        int d = (x >> b) & 1;

        nr = tr[nr].ch[d];
        nl = tr[nl].ch[d];

        if (!nr || tr[nr].cnt - tr[nl].cnt == 0)
            return 0;
    }

    int sz = 1;
    cur[0] = {nr, nl};

    int ans = 0;

    for (int b = hi; b >= lo; --b) {
        int ns = 0;

        if ((mask >> b) & 1) {
            int want = ((x >> b) & 1) ^ 1;

            bool ok = false;

            for (int i = 0; i < sz; ++i) {
                int rr = tr[cur[i].r].ch[want];
                int ll = tr[cur[i].l].ch[want];

                if (tr[rr].cnt - tr[ll].cnt > 0) {
                    ok = true;
                    break;
                }
            }

            int take = ok ? want : want ^ 1;

            if (ok) ans |= 1 << b;

            for (int i = 0; i < sz; ++i) {
                int rr = tr[cur[i].r].ch[take];
                int ll = tr[cur[i].l].ch[take];

                if (tr[rr].cnt - tr[ll].cnt > 0)
                    nxt[ns++] = {rr, ll};
            }
        } else {
            // mask 这一位为 0：两个分支都合法
            for (int i = 0; i < sz; ++i) {
                for (int d = 0; d < 2; ++d) {
                    int rr = tr[cur[i].r].ch[d];
                    int ll = tr[cur[i].l].ch[d];

                    if (tr[rr].cnt - tr[ll].cnt > 0)
                        nxt[ns++] = {rr, ll};
                }
            }
        }

        sz = ns;
        memcpy(cur, nxt, sz * sizeof(State));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        // prefix xor
        pre[0] = 0;
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] ^ a[i];

        // Persistent Trie
        int nodes = 1;
        tr[0] = {{0, 0}, 0};
        root[0] = 0;

        for (int i = 0; i <= n; ++i) {
            int old = root[i];
            int neu = nodes++;

            tr[neu] = tr[old];
            ++tr[neu].cnt;

            int u = old, v = neu;

            for (int b = B - 1; b >= 0; --b) {
                int d = (pre[i] >> b) & 1;

                int oldc = tr[u].ch[d];
                int newc = nodes++;

                tr[newc] = tr[oldc];
                ++tr[newc].cnt;

                tr[v].ch[d] = newc;

                u = oldc;
                v = newc;
            }

            root[i + 1] = neu;
        }

        // previous >=
        int top = 0;

        for (int i = 1; i <= n; ++i) {
            while (top && a[st[top]] < a[i])
                --top;

            L[i] = top ? st[top] + 1 : 1;
            st[++top] = i;
        }

        // next >
        top = 0;

        for (int i = n; i >= 1; --i) {
            while (top && a[st[top]] <= a[i])
                --top;

            R[i] = top ? st[top] - 1 : n;
            st[++top] = i;
        }

        int ans = 0;

        for (int x = 1; x <= n; ++x) {
            int m = a[x];
            if (m == 0) continue;

            int al = L[x] - 1;
            int ar = x - 1;

            int bl = x;
            int br = R[x];

            int sa = ar - al + 1;
            int sb = br - bl + 1;

            if (sa <= sb) {
                for (int u = al; u <= ar; ++u) {
                    int ql = bl;
                    int qr = br;

                    // 排除长度 1 的 [x,x]
                    if (u == x - 1)
                        ++ql;

                    if (ql <= qr)
                        ans = max(ans, query(pre[u], ql, qr, m));
                }
            } else {
                for (int v = bl; v <= br; ++v) {
                    int ql = al;
                    int qr = ar;

                    if (v == x)
                        --qr;

                    if (ql <= qr)
                        ans = max(ans, query(pre[v], ql, qr, m));
                }
            }
        }

        cout << ans << '\n';
    }
}