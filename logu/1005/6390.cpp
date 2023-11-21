#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 100;
const int maxn = 1e6 + 10;
pii tr[maxn], f[N];
// int ,nxt[N];
int n = 0;
stack<int> st;
struct node
{
    int l, r;
} a[N];
bool cmp(node a, node b)
{
    return (a.l != b.l) ? (a.l < b.l) : (a.r > b.r);
}
pii query(int x)
{
    pii ans(0,0);
    while (x <= maxn)
    {
        if (ans.first < tr[x].first)
            ans.first = tr[x].first, ans.second = tr[x].second;
        x += x & (-x);
    }
    ans.first++;
    return ans;
}

void insert(int x, int y, int id)
{
    while (x)
    {
        if (tr[x].first < y)
            tr[x].first = y, tr[x].second = id;
        x -= x & (-x);
    }
    return;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        f[i] = query(a[i].r);
        insert(a[i].r, f[i].first, i);
    }
    int maxn_ans = 0;
    int id_ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxn_ans < f[i].first)
            maxn_ans = f[i].first, id_ans = i;
    }
    while (id_ans != 0)
    {
        st.push(id_ans);
        id_ans = f[id_ans].second;
    }
    cout << maxn_ans << endl;
    while (!st.empty())
    {
        int now = st.top();
        st.pop();
        cout << a[now].l << " " << a[now].r << endl;
    }
    return 0;
}