// https://www.luogu.com.cn/problem/P1886
// 单调队列
// 24.9.19 upd: 更整洁
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        if (dq.front() == i - m) {
            dq.pop_front();
        }
        while (not dq.empty() and a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= m - 1) {
            cout << a[dq.front()] << " \n"[i == n - 1];
        }
    }

    dq.clear();
    for (int i = 0; i < n; i++) {
        if (dq.front() == i - m) {
            dq.pop_front();
        }
        while (not dq.empty() and a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= m - 1) {
            cout << a[dq.front()] << " \n"[i == n - 1];
        }
    }

    return 0;
}