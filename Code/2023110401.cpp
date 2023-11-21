#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Local
using namespace std;
typedef long long ll;

int dig[60];
void dig2(int p)
{
    int i = 0;
    while (p)
    {
        if (p % 2)
            dig[i]++;
        p >>= 1;
        i++;
    }
}
void sol()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < 60; i++)
    {
        dig[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        dig2(a);
    }
    // 6 6 3 1[]
    // for (int i = 0; i <= 10; i++)
    // {
    //     cout << dig[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i <= 40; i++)
    {
        if (dig[i + 1] > dig[i])
        {
            int now = i + 1;
            int del = (dig[i + 1] - dig[i] + 1) / 2;
            // while (dig[now+1]> dig[now] - del ) now ++;
            while (dig[ now +1] == dig[now]) {
                dig[now ]+=del;
                now ++;
            }
            dig[now] -= del;
            dig[0] += 2 * del;
        }
    }
    cout << dig[0] << endl;
}

int main()
{
#ifdef Local
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}