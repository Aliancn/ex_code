#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Local
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int maxm = 2e5 + 10;
const int maxk = 5e5 + 10;
struct Node
{
    int a, b, id, dep;
} st[maxk];
int n, m, k;
int g[maxn];
int pos[maxn + maxm];
int f[maxn + maxm][25], dep[maxn + maxm];
vector<int> G[maxn + maxm];

void add(int u, int v)
{
    G[v].push_back(u);
}

void dfs(int u)
{
    for (int i = 1; i <= 20; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == f[u][0])
            continue;
        f[v][0] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int LCA(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int j = 20; j >= 0; j--)
    {
        if (dep[f[u][j]] >= dep[v])
        {
            u = f[u][j];
        }
    }
    if (u == v)
        return u;
    for (int j = 20; j >= 0; j--)
    {
        if (f[u][j] != f[v][j])
            u = f[u][j], v = f[v][j];
    }
    return f[u][0];
}

bool cmp(Node x, Node y)
{
    return (x.dep == y.dep) ? (x.id < y.id) : (x.dep > y.dep);
}
void sol()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        pos[i] = i;
        cin >> g[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(pos[u], n + i);
        add(pos[v], n + i);
        pos[v] = n + i;
        // cout<<u<<" "<<v;
    }
    for (int i = m + n; i >= 1; i--)
    {
        if (f[i][0] == 0)
        {
            dfs(i);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        // cout << "st";
        int a, b;
        cin >> a >> b;
        // cout << a << b;
        int lca = LCA(a, b);
        // cout<<"mid";
        if (!lca)
            continue;
        Node tmp;
        tmp.a = a, tmp.b = b, tmp.dep = dep[lca], tmp.id = i;
        cnt++;
        st[cnt] = tmp;
        // cout << "end";
    }

    sort(st + 1, st + 1 + cnt, cmp);
    ll ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int des = min(g[st[i].a], g[st[i].b]);
        g[st[i].a] -= des;
        g[st[i].b] -= des;
        ans += 2 * des;
    }
    cout << ans;
}

int main()
{
#ifdef Local
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}