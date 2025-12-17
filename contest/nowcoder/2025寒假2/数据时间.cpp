#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, m, h;
    cin >> n >> h >> m;

    set<string> u, v, w;

    while (n--) {
        string id;
        string date, time;
        cin >> id >> date >> time;
        
        int hh = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        // cerr << hh << " " << mm << endl;
        if (hh != h or mm != m) {
            continue;
        }
        int tt{};
        tt += stoi(time.substr(0, 2)) * 60 * 60;
        tt += stoi(time.substr(3, 2)) * 60;
        tt += stoi(time.substr(6, 2));
        // cerr << tt << endl;
        if (25200 <= tt and tt <= 32400) {
            u.insert(id);
        }
        if (18 * 3600 <= tt and tt <= 20 * 3600) {
            u.insert(id);
        }
        if (11 * 3600 <= tt and tt <= 13 * 3600) {
            v.insert(id);
        }
        if (22 * 3600 <= tt and tt <= 24 * 3600) {
            w.insert(id);
        }
        if (0 <= tt and tt <= 1 * 3600) {
            w.insert(id);
        }
    }
    cout << u.size() << " " << v.size() << " " << w.size() << "\n";

    return 0;
}