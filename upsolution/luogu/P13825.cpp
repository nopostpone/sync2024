#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct Node {
    Node *ls, *rs;
    int l, r;
    u64 sum, tag;

    Node() = delete;
    Node(int l, int r) : l(l), r(r), sum(0), tag(0) {
        ls = rs = nullptr;
    }

    void apply(u64 t) {
        sum += t * (r - l);
        tag += t;
    }
    void pull() {
        sum = ls->sum + rs->sum;
    }
    void push() {
        if (!ls) {
            int m = (l + r) / 2;
            ls = new Node(l, m);
            rs = new Node(m, r);
        }
        if (tag) {
            ls->apply(tag);
            rs->apply(tag);
            tag = 0;
        }
    }

    void rangeAdd(int x, int y, u64 k) {
        if (l >= y or r <= x) {
            return;
        }
        if (l >= x and r <= y) {
            apply(k);
            return;
        }
        push();
        ls->rangeAdd(x, y, k);
        rs->rangeAdd(x, y, k);
        pull();
    }

    u64 rangeSum(int x, int y) {
        if (l >= y or r <= x) {
            return 0;
        }
        if (l >= x and r <= y) {
            return sum;
        }
        push();
        return ls->rangeSum(x, y) + rs->rangeSum(x, y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    auto root = new Node(1, n + 1);

    while (q--) {
        int o, l, r;
        cin >> o >> l >> r;
        r++;

        if (o == 1) {
            u64 k;
            cin >> k;
            root->rangeAdd(l, r, k);
        } else {
            auto ans = root->rangeSum(l, r);
            ans += 1ll * (l + r - 1) * (r - l) / 2;
            cout << ans << "\n";
        }
    }

    return 0;
}