#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;

int n, m;
struct table {
    string name;
    string col[N];
    int x, y;
    string a[N][N];
} t[N];

struct sql {
    string qcol, qname, qhead;
    string val;
    vector<string> qco;
    vector<int> qcoid;
    vector<int> fnd;
    int qhdid;
    void jx() {
        int loc;
        for (int i = 1; i <= n; i++) {
            if (t[i].name == qname) {
                loc = i;
                break;
            }
        }
        while (qcol.find(',') != string::npos) {
            qco.push_back(qcol.substr(0, qcol.find(',')));
            qcol.erase(0, qcol.find(',') + 1);
        }
        qco.push_back(qcol);
        for (auto j : qco)
            for (int i = 1; i <= t[loc].y; i++) {
                if (j == t[loc].col[i]) {
                    qcoid.push_back(i);
                }
            }

        for (int i = 1; i <= t[loc].y; i++) {
            if (t[loc].col[i] == qhead) {
                this->qhdid = i;
                break;
            }
        }
        for (int i = 1; i <= t[loc].x; i++) {
            if (t[loc].a[i][qhdid] == val) {
                fnd.push_back(i);
            }
        }
        for (auto i : fnd) {
            for (auto j : qcoid) {
                cout << t[loc].a[i][j] << " ";
            }
            cout << endl;
        }
    }
} q[1005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].name >> t[i].x >> t[i].y;
        for (int j = 1; j <= t[i].x; j++) {
            for (int k = 1; k <= t[i].y; k++) {
                cin >> t[i].a[j][k];
            }
        }
        for (int j = 1; j <= t[i].y; j++) {
            t[i].col[j] = t[i].a[1][j];
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s1, s2, s3, tmp;
        cin >> s1 >> q[i].qcol >> s2 >> q[i].qname >> s3 >> tmp;
        q[i].qhead = tmp.substr(0, tmp.find('='));
        // cout << q[i].qhead << endl;
        tmp.erase(0, tmp.find('=') + 1);
        q[i].val = tmp;
        // cout << tmp.size() << endl;
    }
    for (int i = 1; i <= m; i++) {
        q[i].jx();
    }
}

int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}