#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 7;
#define ll long long
ll a[maxn];
#define sc scanf
#define pr printf
int pos[40];
void ff(ll x)
{
    for (int i = 0; i < 32; i++)
    {
        if (x >> i & 1)
            pos[i]++;
    }
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out1.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        memset(pos, 0, sizeof(pos)); // 清零
        for (int i = 0; i < n; i++)
        {
            sc("%lld", &a[i]);
            ff(a[i]); // 转化为按位
        }
        for (int i = 0; i < 32; i++)
            sum += pos[i];
        int ans = 0;
        while (sum)
        {
            int i = 0;
            ans++;
            for (; i < 32; i++)
            {
                if (pos[i] >= 1)
                {
                    pos[i]--, sum--;
                    continue;
                }
                else
                {
                    int qwq = -1;
                    for (int j = i; j < 32; j++)
                        if (pos[j] >= 1)
                        {
                            qwq = j;
                            break;
                        }
                    if (qwq == -1)
                        break;
                    for (int j = i; j < qwq; j++)
                    {
                        pos[j]++, sum++;
                    }
                    pos[qwq]--, sum--;
                }
            }
        }
        pr("%d\n", ans);
    }
    return 0;
}