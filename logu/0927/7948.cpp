// 09 27
// 将不需要管的顺序去除 发现题目中的单调性
// 注意数据的范围
#include <iostream>
#include <cstring>
#include <algorithm>
#define Local
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 7;
int n, q;
ll a[maxn];
ll sum[maxn];
ll ans[maxn];
struct node
{
    /* data  */
    int pos;
    int k;
} c[maxn];
bool cmp(const node a, const node b)
{
    return a.k > b.k;
}
void sol()
{
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    memset(sum, 0, sizeof(sum));
    memset(ans, 0, sizeof(ans));
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> c[i].k;
        c[i].pos = i;
    }
    sort(a + 1, a + 1 + n);
    sort(c + 1, c + 1 + q, cmp);

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    int now = 1;
    for (int i = 1; i <= q; i++)
    {
        ans[c[i].pos] = 0;
        while (now <= n && ((double)a[now] < double(sum[n] - sum[now - 1]) / double(n - now + 1) - (double)c[i].k))
        {
            now++;
        }
        ans[c[i].pos] = n - now + 1;
        // cout<<"ans :" <<c[i].pos<<" "<<ans[c[i].pos] <<endl;
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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