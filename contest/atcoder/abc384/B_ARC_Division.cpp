#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, r;
    cin >> n >> r;

    int now{r};

    while (n--) {
        int t, a;
        cin >> t >> a;
        if (t == 1 and 1600 <= now and now <= 2799) {
            now += a;
        }
        if (t == 2 and 1200 <= now and now <= 2399) {
            now += a;
        }
    }
    cout << now << endl;
    
    return 0;
}