// 09 27

#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 200007;
int n, p;
int a[maxn];
int m;
int c;

struct segmentTree
{
    ll sum[maxn << 2], mtp[maxn << 2], inc[maxn << 2];

    void down(int l, int r, int now)
    {
        if (mtp[now] == 1 && inc[now] == 0)
            return;
        if (l != r)
        {
            mtp[now << 1] = mtp[now << 1] * mtp[now] % p;
            mtp[now << 1 | 1] = mtp[now << 1 | 1] * mtp[now] % p;
            inc[now << 1] = (inc[now << 1] * mtp[now] % p + inc[now]) % p;
            inc[now << 1 | 1] = (inc[now << 1 | 1] * mtp[now] % p + inc[now]) % p;
        }
        sum[now] = (sum[now] * mtp[now] % p + inc[now] * (r - l + 1) % p) % p;
        mtp[now] = 1, inc[now] = 0;
    }

    void build(int l, int r, int now)
    {
        mtp[now] = 1, inc[now] = 0;
        if (l == r)
        {
            sum[now] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, now << 1);
        build(mid + 1, r, now << 1 | 1);
        sum[now] = sum[now << 1] + sum[now << 1 | 1];
    }

    ll querysum(int x, int y, int l, int r, int now)
    {
        down(l, r, now);
        if (x <= l && r <= y)
        {
            return sum[now];
        }
        ll ret = 0;
        int mid = (r + l) >> 1;
        if (mid >= x)
            ret = (ret + querysum(x, y, l, mid, now << 1)) % p;
        if (mid + 1 <= y)
            ret = (ret + querysum(x, y, mid + 1, r, now << 1 | 1)) % p;
        return ret;
    }
    void rangeadd(int x, int y, int l, int r, int now)
    {
        down(l, r, now);
        if (x <= l && r <= y)
        {
            inc[now] = (inc[now] + c) % p;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            rangeadd(x, y, l, mid, now << 1);
        }
        if (mid + 1 <= y)
        {
            rangeadd(x, y, mid + 1, r, now << 1 | 1);
        }
        down(l, mid, now << 1), down(mid + 1, r, now << 1 | 1);
        sum[now] = (sum[now << 1] + sum[now << 1 | 1]) % p;
    }
    void rangemtp(int x, int y, int l, int r, int now)
    {
        down(l, r, now);
        if (x <= l && r <= y)
        {
            mtp[now] = (mtp[now] * c) % p;
            inc[now] = (inc[now] * c) % p;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            rangemtp(x, y, l, mid, now << 1);
        }
        if (mid + 1 <= y)
        {
            rangemtp(x, y, mid + 1, r, now << 1 | 1);
        }
        down(l, mid, now << 1), down(mid + 1, r, now << 1 | 1);
        sum[now] = (sum[now << 1] + sum[now << 1 | 1]) % p;
    }
} tree;

int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // cout<<"here"<<endl;
    tree.build(1, n, 1);
    // cout<<"here"<<endl;
    cin >> m;
    while (m--)
    {
        int op;
        cin >> op;
        int x, y;
        switch (op)
        {
        case 1:
            cin >> x >> y >> c;
            tree.rangemtp(x, y, 1, n, 1);
            break;
        case 2:
            cin >> x >> y >> c;
            tree.rangeadd(x, y, 1, n, 1);
            break;
        case 3:
            cin >> x >> y;
            cout << tree.querysum(x, y, 1, n, 1) << endl;
            break;
        }
    }
    return 0;
}