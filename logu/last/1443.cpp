#include<iostream>
#include<queue>
using namespace std;

int m,n;
int amp[405][405],vis[405][405];
int x,y;
queue <pair<int ,int >> q;
int bu[9][2] ={{1,2},{2,1},{-1,2},{-2,1},{-1,-2},{-2,-1},{1,-2},{2,-1}};
int main(){
    freopen("in.in","r",stdin);
    freopen ("out.out","w",stdout);

    cin>>n>>m>>x>>y;
    q.push(make_pair(x,y));
    vis[x][y]=1;
    while(!q.empty()){
        pair<int ,int> temp = q.front();
        q.pop();
        int tx,ty;
        for(int i=0;i<8;i++){
            tx=temp.first+bu[i][0];
            ty=temp.second+bu[i][1];
            if(tx>0&&tx<=n&&ty>0&&ty<=m&&vis[tx][ty]==0){
                q.push(make_pair(tx,ty));
                vis[tx][ty]=vis[temp.first][temp.second]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]) {
                printf("%-5d",-1);
            }
            if(vis[i][j]){
                printf("%-5d",vis[i][j]);
            }
        }
        cout<<endl;
    }
    return 0;
}