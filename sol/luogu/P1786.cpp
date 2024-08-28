#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr int inf = 2e9;

struct Node {
    string name, job;
    int id, money, lvl;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<Node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].job >> a[i].money >> a[i].lvl;
        a[i].id = i;
    }

    map<string, int> f;
    f["BangZhu"] = -2;
    f["FuBangZhu"] = -1;
    f["HuFa"] = 0;
    f["ZhangLao"] = 1;
    f["TangZhu"] = 2;
    f["JingYing"] = 3;
    f["BangZhong"] = 4;

    vector<string> g(5);
    for (auto &&[str, i] : f) {
        if (i >= 0)
            g[i] = str;
    }
    sort(a.begin(), a.end(), [](Node &x, Node &y) { return x.money == y.money ? x.id < y.id : x.money > y.money;});

    int cnt[] = {2, 4, 7, 25, inf};
    int pos = 0;
    for (auto &I : a) {
        int JOB = f[I.job];
        if (JOB < 0) {
            continue;
        }
        I.job = g[pos];
        if (--cnt[pos] == 0) {
            pos++;
        }
    }

    sort(a.begin(), a.end(), [&](auto x, auto y) { return x.job == y.job ? x.lvl == y.lvl ? x.id < y.id : x.lvl > y.lvl : f[x.job] < f[y.job];});

    for (int i = 0; i < n; i++) {
        cout << a[i].name << " " << a[i].job << " " << a[i].lvl << endl;
    }

    return 0;
}