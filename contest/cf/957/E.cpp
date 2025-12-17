#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
int n;
int ch[15];
int mx;

void pro(ll x) {
    mx = 0;
    int xx = x;
    for (int i = 1; i <= 9; i++) {
        ch[i] = x % 10;
        x /= 10;
        if (ch[i] != 0)
            mx = i;
    }
    reverse(ch + 1, ch + mx + 1);
    for (int i = mx + 1; i <= 9; i++)
        ch[i] = ch[i - mx];
}

vector<pair<int, int>> V[105];

void init() {
    for (int i = 1; i <= 100; i++) {
        pro(i);
        for (int j = 1; j <= 10000; j++) {
            ll yuan = i * j;
            ll now = 0;
            for (int k = 1; k <= 9; k++) {
                now = now * 10;
                now += ch[k];
                ll cha = yuan - now;
                if (cha > min(10000LL, yuan) || cha == 0)
                    continue;
                if (mx * j - cha == k)
                    V[i].push_back(make_pair(j, cha));
            }
        }
        sort(V[i].begin(), V[i].end());
    }
}

int main() {
    cin >> t;
    init();
    while (t--) {
        cin >> n;
        cout << V[n].size() << endl;
        for (auto to : V[n]) {
            cout << to.first << ' ' << to.second << endl;
        }
    }
}
