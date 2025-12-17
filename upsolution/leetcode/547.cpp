#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bitset<200> vis;
    vector<vector<int>> g;
    void dfs(int now)
    {
        if (vis[now])
            return;
        vis[now] = true;
        for (auto &to : g[now])
        {
            if (vis[to])
                continue;
            dfs(to);
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = (isConnected[0]).size();
        std::vector<int> temp(n);
        g.resize(n, temp);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1 and i != j)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i), cnt++;
        return cnt;
    }
};
