#include <iostream>
#define Local
using namespace std;
typedef long long ll;
const int mod = 1e8;
const int maxn = 20;

int mp[maxn][maxn]; // 原始的地图状态
int F[13];          // 每一行的状态
int f[13][1 << 12 + 5];
int m, n;
bool check[1 << 12 + 5];

void sol()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
            F[i] = (F[i] << 1) + mp[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        check[i] = (!(i & (i << 1))) && (!(i & (i >> 1)));
    }

    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            if (check[j] && ((j & F[i]) == j))
            {
                for (int k = 0; k < (1 << n); k++)
                {
                    if ((k & j) == 0)
                    {
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        ans = (ans + f[m][i]) % mod;
    }
    cout << ans << endl;
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