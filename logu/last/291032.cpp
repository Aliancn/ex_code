#include <bits/stdc++.h>
using namespace std;
//******************************************
#define LOCAL
int a[40000 + 5][10];
int n, k;

bool check(int x, int y, int k)
{
    for (int i = 1; i <= k; i++)
    {
        if (a[x][i] < a[y][i])
            return false;
    }
    return true;
}

signed main()
{
    clock_t cl = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //*************************************
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[j][i]);
        }
    }
    int num = 0;
    int ans[1000];
    for (int i = 1; i < n; i++)
    { // i差树
        int flag = 0;
        int test = 1;
        // int test_flag = 0;
        if (i == 1)
        {
            for (int j = 1; j < n; j++)
            {
                if (!check(j, j + 1, k))
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                ans[++num] = i;
        }
        else
        {
            int y = 0;
            while (test < n)
            {
                y++;
                test+=pow(i,y);
                
            }
            // if(!test_flag) continue;
            for (int j = 1; j <= y; j++)
            {
                for (int l = 1; l <= pow(i, j - 1); l++)
                {
                    for (int m = i-1; m >= 0; m--){
                        if((pow(i, j)- 1) / (i - 1) + l * i - m>n) break;
                        if (!check((pow(i, j - 1)-1) / (i - 1) + l, (pow(i, j)- 1) / (i - 1) + l * i - m, k))
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
            if (!flag)
                ans[++num] = i;
        }
    }
    cout << num << endl;
    for (int i = 1; i <= num; i++)
    {
        cout << ans[i] << " ";
    }

    //*************************************
end:
    cerr << "time used: " << clock() - cl << " ms " << endl;
    return 0;
}