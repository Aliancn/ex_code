#include <iostream>
#include <algorithm>
#define Local
using namespace std;
typedef long long ll;
const int maxn = 2000;
int m, n, k;
int mp[maxn][maxn];
int l_up[maxn][maxn];
int l_down[maxn][maxn];
int r_up[maxn][maxn];
int r_down[maxn][maxn];
void sol()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp = 0;
            cin >> tmp;
            mp[i][j] = mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1] + tmp;
        }
    }
    for (int i = n; i >= k; i--)
    {
        for (int j = m; j >= k; j--)
        {
            mp[i][j] -= mp[i - k][j] + mp[i][j - k] - mp[i - k][j - k];
        }
    }
    // a
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        {
            l_up[i][j] = max(mp[i][j], max(l_up[i - 1][j], l_up[i][j - 1]));
        }
    }
    // B
    for (int i = k; i <= n; i++)
    {
        for (int j = m; j >= k; j--)
        {
            r_up[i][j] = max(mp[i][j], max(r_up[i - 1][j], r_up[i][j + 1]));
        }
    }
    // C
    for (int i = n; i >= k; i--)
    {
        for (int j = k; j <= m; j++)
        {
            l_down[i][j] = max(mp[i][j], max(l_down[i + 1][j], l_down[i][j - 1]));
        }
    }
    // D
    for (int i = n; i >= k; i--)
    {
        for (int j = m; j >= k; j--)
        {
            r_down[i][j] = max(mp[i][j], max(r_down[i + 1][j], r_down[i][j + 1]));
        }
    }
    // cout << "ok" << endl;
    int ans = 0;
    // 1
    for (int i = k; i <= n - k; i++)
    {
        for (int j = k; j <= m - k; j++)
        {
            ans = max(ans, l_up[i][j] + r_up[i][j + k] + l_down[i + k][m]);
        }
    }
    // 2
    for (int i = k; i <= n - k; i++)
    {
        for (int j = k; j <= m - k; j++)
        {
            ans = max(ans, l_up[i][m] + l_down[i + k][j] + r_down[i + k][j + k]);
        }
    }
    for (int i = k; i <= n - k; i++)
    {
        for (int j = k; j <= m - k; j++)
        {
            ans = max(ans, l_up[i][j] + r_up[n][j + k] + l_down[i + k][j]);
        }
    }
    for (int i = k; i <= n - k; i++)
    {
        for (int j = k; j <= m - k; j++)
        {
            ans = max(ans, l_up[n][j] + r_up[i][j + k] + r_down[i + k][j + k]);
        }
    }
    for (int i = k; i <= n - k; i++)
    {
        for (int j = k + k; j <= m - k; j++)
        {
            ans = max(ans, l_up[n][j - k] + r_up[n][j + k] + mp[i][j]);
        }
    }
    for (int i = k + k; i <= n - k; i++)
    {
        for (int j = k; j <= m - k; j++)
        {
            ans = max(ans, l_up[i - k][m] + l_down[i + k][m] + mp[i][j]);
        }
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