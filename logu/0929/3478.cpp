/*
读入的边数错误
*/
#include <iostream>
#include <queue>
#include <vector>
#define Local
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
int n = 0;
vector<int> mp[maxn];
int siz[maxn];
int dep[maxn];
ll f[maxn];
void dfs_init(int x, int fa)
{
    siz[x] = 1;
    dep[x] = dep[fa] + 1;
    for (int i = 0; i < mp[x].size(); i++)
    {
        int nxt = mp[x][i];
        if (nxt != fa)
        {
            dfs_init(nxt, x);
            siz[x] += siz[nxt];
        }
    }
}

void dfs_ans(int x, int fa)
{
    for (int i = 0; i < mp[x].size(); i++)
    {
        int nxt = mp[x][i];
        if (nxt != fa)
        {
            f[nxt] = f[x] + n - 2 * siz[nxt];
            dfs_ans(nxt, x);
        }
    }
}
void sol()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    // cout << "1" << endl;
    dfs_init(1, 0);
    for (int i = 1; i <= n; i++)
        f[1] += dep[i];
    // cout << "2" << endl;
    dfs_ans(1, 0);
    // ll ans = 0;
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        // cout<<"==>"<<i <<" "<<f[i]<<endl;
        if (f[pos] < f[i])
        {
            // ans = f[i];
            pos = i;
        }
    }
    cout << pos << "\n";
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