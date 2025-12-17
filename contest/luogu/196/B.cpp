#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int wa, ca, ta, wb, cb, tb;
    cin >> wa >> ca >> ta >> wb >> cb >> tb;

    if (wa == wb ? ca == cb ? ta < tb : ca > cb : wa > wb) {
        cout << "A";
    } else {
        cout << "B";
    }
    
    return 0;
}