// root = rangeMin
vector<int> lc(n, -1), rc(n, -1);
vector<int> stk;
for (int i = 0; i < n; i++) {
    while (not stk.empty() and p[i] < p[stk.back()]) {
        int x = stk.back();
        stk.pop_back();

        rc[x] = lc[i];
        lc[i] = x;
    }
    stk.push_back(i);
}
while (stk.size() > 1) {
    int x = stk.back();
    stk.pop_back();
    rc[stk.back()] = x;
}