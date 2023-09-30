#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
/*
朴素思路肯定是以每个点作为根节点，做一次dfs累加深度
但是这样在1e6的数据范围O(n2)会超时

发现相连节点换根时存在性质：
原根节点所包含深度全部+1，
现根节点做包含深度全部-1（包含自身）

所以我们任选一根，算出他的max值以及
预处理各个子树的大小（方便直接+size而不是累加+1）

max值用来做接下来的转移起点
*/

const int N = 1000105;
ll n, ans, num = 1, ansnum, maxd;
vector<int> a[N];
ll vis[N];
ll dp[N], size[N], dep[N];

void dfs(int u)
{
    vis[u] = 1;
    size[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if (vis[v])
            continue; // 莫忘
        dfs(v);
        dep[v] = dep[u] + 1; // 固定根节点的深度记录
        size[u] += size[v];  // 大小累加就可以了
    }
}

void zhuanyi(int u)
{
    vis[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i]; // 相邻点皆可可知转移性换根
        if (vis[v])
            continue;
        dp[v] = dp[u] - size[v] + (n - size[v]); //-与v相连+与u相连的
        if (dp[v] > dp[1])
        {
            dp[1] = dp[v];
            num = v;
        }
        zhuanyi(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); // 来自ssx的快读！
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1); // 标记一下
    for (int i = 1; i <= n; i++)
    {
        dp[1] += dep[i];
    }
    memset(vis, 0, sizeof(vis));
    zhuanyi(1); // 换根
    cout << num << endl;
    // num要初始化成1这种有意义的数！！！
    return 0;
}