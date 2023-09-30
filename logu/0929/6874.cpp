// 二分
#include <iostream>
#include <algorithm>
#include <cmath>
#define Local
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
ll a[maxn], b[maxn];
int n;

bool check(ll mid)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x = mid + abs(n / 2 + 1 - i);
        res += (a[i] >= x) + (b[i] >= x);
    }
    return res >= n;
}

void sol()
{
    cin >> n;
    ll l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        r = max(r, b[i]);
    }
    // cout<<"ok"<<endl;
    ll ans = 0;
    while (l <= r)
    {
        // cout<<" dsa";
        // cout << "ok" << endl;
        ll mid = (l + r) >> 1ll;
        check(mid) ? l = mid + 1, ans = mid : r = mid-1;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x = ans + abs(n / 2 + 1 - i);
        sum += abs(a[i] - x) + abs(b[i] - x);
    }
    cout << sum << endl;
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