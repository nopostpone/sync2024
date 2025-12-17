#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ask(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    int r;
    cin >> r;
    assert(r != -1);
    return r == 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, mm, q;
    cin >> n >> mm >> q;

    set<int, greater<int>> res;

    vector<int> s1, d1;
    for (int i = 0; i < n; i += 2) {
        if (ask(i, i + 1)) {
            s1.push_back(i);
        } else {
            d1.push_back(i);
        }
    }

    if (s1.size() % 2 == 1) {
        s1.push_back(s1.front());
    }

    vector<int> s2, d2;
    for (int i = 0; i < s1.size(); i++) {
        if (ask(s1[i], s1[i + 1])) {
            s2.push_back(i);
        } else {
            d2.push_back(i);
        }
    }

    if (s2.size() % 2 == 1) {
        s2.push_back(s2.front());
    }

    vector<int> s3, d3;
    for (int i = 0; i < s2.size(); i++) {
        if (ask(s1[s2[i]], s1[s2[i + 1]])) {
            s3.push_back(i);
        } else {
            d3.push_back(i);
        }
    }

    int te = -1, de = -1;
    for (int i = 1; i < s3.size(); i++) {
        if (ask(s1[s2[s3[i]]], s1[s2[s3[i + 1]]])) {
            te = s1[s2[s3[i]]];
        } else {
            de = i;
        }
    }
    if (s3.size() % 2 == 0) {
        if (te, s1[s2[s3.back()]]) {
            de = s3.size() - 1;
        }
    }

    if (de != -1) {
        if (ask(te, s1[s2[s3[de]]])) {
            res.insert(s1[s2[s3[de + 1]]]);
            res.insert(s1[s2[s3[de + 1]]] + 1);
            res.insert(s1[s2[s3[de + 1]] + 1]);
            res.insert(s1[s2[s3[de + 1]] + 1] + 1);
            res.insert(s1[s2[s3[de + 1] + 1]]);
            res.insert(s1[s2[s3[de + 1] + 1]] + 1);
            res.insert(s1[s2[s3[de + 1] + 1] + 1]);
            res.insert(s1[s2[s3[de + 1] + 1] + 1] + 1);
        } else {
            res.insert(s1[s2[s3[de]]]);
            res.insert(s1[s2[s3[de]]] + 1);
            res.insert(s1[s2[s3[de]] + 1]);
            res.insert(s1[s2[s3[de]] + 1] + 1);
            res.insert(s1[s2[s3[de] + 1]]);
            res.insert(s1[s2[s3[de] + 1]] + 1);
            res.insert(s1[s2[s3[de] + 1] + 1]);
            res.insert(s1[s2[s3[de] + 1] + 1] + 1);
        }
    }
    for (auto i : d1) {
        if (ask(te, i)) {
            res.insert(i + 1);
        } else {
            res.insert(i);
        }
    }
    for (auto i : d2) {
        if (ask(te, s1[i])) {
            res.insert(s1[i + 1]);
            res.insert(s1[i + 1] + 1);
        }
        res.insert(s1[i]);
        res.insert(s1[i] + 1);
    }
    for (auto i : d3) {
        if (ask(te, s1[s2[i]])) {
            res.insert(s1[s2[i + 1]]);
            res.insert(s1[s2[i + 1] + 1]);
            res.insert(s1[s2[i + 1]] + 1);
            res.insert(s1[s2[i + 1] + 1] + 1);
        }
        res.insert(s1[s2[i]]);
        res.insert(s1[s2[i] + 1]);
        res.insert(s1[s2[i]] + 1);
        res.insert(s1[s2[i] + 1] + 1);
    }

    cout << "! ";
    for (auto it = res.rbegin(); it != res.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}