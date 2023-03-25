#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m = 30, n = 50;
	
bool checkL(int x, int y)  //判断坐标是否超出边界 
{
	if(x >= 0 && y >= 0 && x < m && y < n)
		return true;
	else 
		return false;
}

int main()
{
        freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	string s[50];
	for(int i = 0; i < m; i++)
		cin >> s[i];
	
	int cnt = 0;
	int cnx[5] = {1, -1, 1, 1, 0};
	int cny[5] = {1, 1, -1, 0, 1};
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < 5; k++)
			{
				int x = i, y = j;
				while(checkL(x, y))
				{
					if(s[x][y] > s[i][j])
						cnt++;
					x += cnx[k];
					y += cny[k];
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
