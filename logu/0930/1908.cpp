#include <iostream>
#include <algorithm>
#define Local
#define For(i, sta, en) for (int i = sta; i <= en; i++)
using namespace std;
typedef long long ll;
#define lowbit(x) x & (-x)
const int maxn = 5e5 + 10;
int n;
struct point
{
    int num;
    int val;
} a[maxn];
int tree[maxn];
int ranks[maxn];
inline bool cmp(point a, point b)
{
    if (a.val == b.val)
    {
        return a.num < b.num;
    }
    return a.val < b.val;
}

inline void insert(int p, int d)
{
    for (; p; p += lowbit(p))
    {
        tree[p] += d;
    }
}

inline int query(int p)
{
    ll sum = 0;
    for (;p; p -= lowbit(p))
    {
        sum += tree[p];
    }
    return sum;
}

void sol()
{
    cin >> n;
    For(i, 1, n)
    {
        cin >> a[i].val;
        a[i].num = i;
    }
    sort (a+1,a+1+n,cmp);
    For(i,1,n){
        ranks[a[i].num] = i;
    }
    ll ans =0;
    For(i,1,n){
        insert(ranks[i],1);
        ans += i- query(ranks[i]);
    }
    cout<<ans ;
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