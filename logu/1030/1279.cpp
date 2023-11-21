#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Local
using namespace std;
typedef long long ll;

int dp[2007][2007];
void sol()
{
    string a, b;
    int k;
    cin >> a >> b >> k;
    int lena = a.length(), lenb = b.length();
    for (int i = 0; i <= max(lena, lenb); i++)
    {
        dp[i][0] = dp[0][i] = i * k;
    }
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            dp[i][j] = min(min(dp[i - 1][j] + k, dp[i][j - 1]+k), dp[i - 1][j - 1] + abs(int(a[i - 1] - b[j - 1])));
        }
    }
    cout<<dp[a.length()][b.length()];
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