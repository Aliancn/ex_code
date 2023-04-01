#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int ax, ay, bx, by;
int ans = 50;
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
string s[2];
void dfs(int a, int p, int x, int y){
    if(s[ax][ay] == 'B' && s[bx][by] == 'A'){
        ans = min(ans, a);
        return ;
    }
    if(a > ans){
        return ;
    }
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx < 2 && dy >= 0 && dy < 3 && p + i != 3){
            swap(s[x][y], s[dx][dy]);
            dfs(a + 1, i, dx, dy);
            swap(s[x][y], s[dx][dy]);
        }
    }
}
int main(){
    while(getline(cin, s[0])){
        getline(cin, s[1]);
        int x = 0, y = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(s[i][j] == 'A'){
                    ax = i;
                    ay = j;
                }
                if(s[i][j] == 'B'){
                    bx = i;
                    by = j;
                }
                if(s[i][j] == ' '){
                    x = i;
                    y = j;
                }
            }
        }
        ans = 50;
        dfs(0, -1, x, y);
        printf("%d\n", ans);
    }
    return 0;
}