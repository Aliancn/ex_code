#include <bits/stdc++.h>
using namespace std;
#define For(i, sta, en) for (int i = sta; i <= en; i++)
#define lowbit(x) x & (-x)
#define speedUp_cin_cout         \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef long long ll;
// typedef __int128 lll;
const int maxn = 5e6 + 9;
ll t[maxn], ans;
int n, m, num[maxn];

void update(int now) // 更新now
{
    while (now <= m)
    {
        t[now]++;
        now += lowbit(now);
    }
}

ll query(int now) // 查询 now 的前缀和
{
    ll an = 0;
    while (now)
    {
        an += t[now];
        now -= lowbit(now);
    }
    return an;
}

int main()
{
    speedUp_cin_cout; // 加速读写
    cin >> n;
    For(i, 1, n) cin >> num[i], m = max(m, num[i]);
    For(i, 1, n)
    {
        // 先查询比它大的数的数目，query(m)是总数，query(num[i])是小于等于num[i]的数的数目，相减可得
        ans += query(m) - query(num[i]);
        // 再加入树状数组
        update(num[i]);
    }
    cout << ans;
    return 0;
}
