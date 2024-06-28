图论

搜索：dfs,bfs

存图方式：邻接表，链式前向星，（邻接矩阵复杂度太大，基本不用）

## 树的遍历（邻接表）：
```cpp
struct edge
{
    ...//存出点和边权以及其他的东西
};
vector<edge> g;

void dfs(int u, int fa)
{
    for(auto &i: g[u])
    {
        if(i==fa)continue;
        dfs(i,u);
    }
}
```

## 求树的每个节点深度：
```cpp
void dfs(int u, int fa)
{
    dep[u]=dep[fa]+1;
    for(auto &i: g[u])
    {
        if(i==fa)continue;
        dfs(i,u);
    }
}

int main()
{
    //存边
    ...
    //初始化
    dep[0]=-1;
    //dfs
    dfs(1,0);
}
```

## 求树的每个节点的子树大小：
```cpp
void dfs(int u, int fa)
{
    for(auto &i: g[u])
    {
        if(i.v==fa)continue;
        dfs(i.v,u);
        sz[u]+=sz[i.v];
    }
    sz[u]=1;
}   

int main()
{
    //存边
    ...
    //初始化
    //dfs
    dfs(1,0);
}
```

## 求每个子树的点权和
```cpp

void dfs(int u, int fa)
{
    for(auto &i: g[u])
    {
        if(i.v==fa)continue;
        dfs(i.v,u);
        sum[u]+=sum[i.v];
    }
}   

int sum[N];

int main()
{
    //存边
    // c[]为点权
    //初始化
    for(auto &u)
    sum[u]=c[u];
    
    dfs(...);
}
```

## 求每个子树中点权的最大值
```cpp

void dfs(int u, int fa)
{
    for(auto &i: g[u])
    {
        if(i.v==fa)continue;
        dfs(i.v,u);
        mx[u]=max(mx[u],mx[i.v]);
    }
}   

int mx[N];

int main()
{
    //存边
    // c[]为点权
    //初始化
    mx[u]=c[u]
}
```

## 树的重心
重心？

去掉重心后，__树中所有连通块的最大尺寸最小__。

```cpp
void dfs(int u, int fa)
{
    // 求 siz[u]
    // 求 n-siz[u] 为删去该点后剩下一大坨的大小
    for(auto &i: g[u])
    {
        if(i.v==fa)continue;
        dfs(i.v,u);
        mx[u]=max(mx[u],mx[i.v]);
    }
}   

int siz[N], mx[u];

int main()
{
    //存边
    // c[]为点权
    //初始化

    dfs(1,0);
}
```

## 每个点到其他节点的距离和
```cpp

```
