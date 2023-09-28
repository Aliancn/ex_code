// 09 27
// 注意循环的顺序
#include <iostream>
#include <algorithm>
#define Local
using namespace std;
const int N = 1e5 + 7;
int n;
int A_1[N], B_1[N]; // +
int A_2[N], B_2[N]; // -
int a1, a2, b1, b2;

bool cmp(int x, int y)
{
    return x > y;
}
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0)
        {
            A_2[++a2] = -tmp;
        }
        else
        {
            A_1[++a1] = tmp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0)
        {
            B_2[++b2] = -tmp;
        }
        else
        {
            B_1[++b1] = tmp;
        }
    }
    sort(A_1 + 1, A_1 + 1 + a1);
    sort(B_1 + 1, B_1 + 1 + b1);
    sort(A_2 + 1, A_2 + 1 + a2);
    sort(B_2 + 1, B_2 + 1 + b2);

    int pos = 1;
    int ans = 0;
    for (int i = 1; i <= a2; i++)
    {
        if (pos <= b1 && B_1[pos] < A_2[i])
        {
            pos++;
            ans++;
        }
    }
    pos = 1;
    for (int i = 1; i <= b2; i++)
    {
        if (pos <= a1 && A_1[pos] < B_2[i])
        {
            pos++;
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
#ifdef Local
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int t = 1;
    // cin>>t;
    while (t--)
    {
        sol();
    }
    return 0;
}