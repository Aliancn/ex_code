#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Local
using namespace std;
typedef long long ll;

int dp[600];
string a[610];
string str;
int w, l;
void sol()
{
    cin >> w >> l;
    cin >> str; // len == l

    for (int i = 1; i <= w; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= l; i++)
    {
        // cout<<i<<"===>";
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= w; j++)
        {
            if (i < a[j].length())
                continue;
            int now = i;
            int des = 0;
            int len = a[j].length();
            bool flag = false;
            while (now > 0 && len > 0)
            {
                if (a[j][len - 1] == str[now - 1])
                {
                    now--;
                    len--;
                }
                else
                {
                    des++;
                    now--;
                }
                if (len == 0)
                {
                    flag = true;
                    break;
                }
                // if (dp[now] + des > dp[i])
                //     break;
            }
            if (flag)
            {
                dp[i] = min(dp[i], dp[now] + des);
                // cout<<dp[i]<<" "<<now<<" "<<des<<endl;
            }
        }
        // cout<<"\nans :" <<dp[i]<<endl;
        // cout<<endl;
    }

    cout << dp[l] << endl;
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