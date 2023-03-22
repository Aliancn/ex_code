#include <iostream>
using namespace std;
int vis[35][65];
int map[35][65];
int l = 60, r = 30;
int ans=0;

void dfs(int x, int y)
{
    if (!vis[x][y]&&map[x][y]==1)
    {
        vis[x][y]=1;
        if (x > 1)
            dfs(x - 1, y);
        if (y > 1)
            dfs(x, y - 1);
        if (x < l)
            dfs(x + 1, y);
        if (y < r)
            dfs(x, y + 1);
    }
}

int main()
{
    freopen("in.in","r",stdin);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            if(!vis[i][j]&&map[i][j]==1){
                dfs(i, j);
                ans++;
            }
            
        }
    }
    cout<<ans;
}