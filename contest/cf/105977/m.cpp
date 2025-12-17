#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, string> f;
    f[0] = "FZU";
    f[1] = "FNU";
    f[2] = "FZU";
    f[3] = "FZU";
    f[4] = "FAFU";
    f[5] = "HQU";
    f[6] = "MJU";
    f[7] = "XMUT";
    f[8] = "QNU";
    f[9] = "JMU";
    f[10] = "FZU";

    int n;
    cin >> n;
    n--;

    cout << f[n];

    return 0;
}