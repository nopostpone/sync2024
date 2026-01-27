#include <bits/stdc++.h>
using namespace std;

// ostream& operator<<(ostream &os, const vector<int> &a) {
//     for (auto x : a) {
//         os << x + 1 << " ";
//     }
//     os << "\n";
//     return os;
// }

// auto check(const auto &a, const auto &b) {
//     const int n = a.size();
//     vector<bool> exi(n);

//     vector<int> stk;
//     auto work = [&](int x) {
//         if (exi[x]) {
//             while (not stk.empty() and stk.back() != x) {
//                 exi[stk.back()] = false;
//                 stk.pop_back();
//             }
//             assert(not stk.empty());
//             exi[stk.back()] = false;
//             stk.pop_back();
//             return true;
//         }

//         exi[x] = true;
//         stk.push_back(x);
//         return false;
//     };

//     int res = 0;

//     for (int i = 0; i < n; i++) {
//         if (work(a[i])) {
//             res++;
//         }
//         work(b[i]);
//     }
//     return res;
// }

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        
        cnt[a[i]]++;
    }

    cout << (cnt[a[0]] == 2) << "\n";
    
    vector<int> p(n, -1);
    for (int x = 0, i = 0; x < n; x++) {
        while (i < n and cnt[i] != 0) {
            i++;
        }
        if (cnt[x] == 2 and x != a[0]) {
            p[x] = i++;
        }
    }
    
    vector<int> seq(n, -1);
    for (int i = 1; i < n; i++) {
        if (p[a[i]] != -1) {
            seq[i - 1] = p[a[i]];
        }
    }

    vector<int> ord;
    for (int i = 0; i < n; i++) {
        cerr << a[i] << endl;
        if (cnt[a[i]] == 1) {
            ord.push_back(a[i]);
        }
    }
    
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (cnt[a[i]] == 1) {
            j = max(j, i);
            while (j < n and seq[j] != -1) {
                j++;
            }
            seq[j] = ord[k++];
        }
    }

    int lst = n - 1;
    while (lst >= 0 and cnt[lst] != 0) {
        lst--;
    }
    for (int i = 0; i < n; i++) {
        if (seq[i] == -1) {
            seq[i] = lst;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << seq[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
3
3
1 2 3
5
3 1 4 1 5
5
1 4 5 1 4
*/