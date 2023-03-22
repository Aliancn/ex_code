/*
1.注意坐标的变换，上下左右不要写错了
2.有的时候正难则反，特别是对于涂色
*/

#include <bits/stdc++.h>
using namespace std;
//******************************************

int a[40][40];
int n;
queue<pair<int, int>> q;

void bfs()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i][1] == 0)
        {
            q.push(make_pair(i, 1));
        }

        if (a[i][n] == 0)
        {
            q.push(make_pair(i, n));
        }
    }
    for (int j = 2; j < n; j++)
    {
        if (a[1][j] == 0)
        {
            q.push(make_pair(1, j));
        }

        if (a[n][j] == 0)
        {
            q.push(make_pair(n, j));
        }
    }

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (int x = temp.first - 1; x <= temp.first + 1; x += 2)
        {
            int y = temp.second;
            if (a[x][y] == 2 && x > 1 && x < n && y > 1 && y < n)
            {
                a[x][y] = 0;
                q.push(make_pair(x, y));
            }
        }
        for (int y = temp.second - 1; y<= temp.second + 1; y += 2)
        {
            int x = temp.first;
            if (a[x][y] == 2 && x > 1 && x < n && y > 1 && y < n)
            {
                a[x][y] = 0;
                q.push(make_pair(x, y));
            }
        }
    }
}

signed main()
{
    clock_t cl = clock();

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    //*************************************
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (i > 1 && i < n && j > 1 && j < n && a[i][j] == 0)
            {
                a[i][j] = 2;
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    //*************************************
end:
    cerr << "time used: " << clock() - cl << " ms " << endl;
    return 0;
}