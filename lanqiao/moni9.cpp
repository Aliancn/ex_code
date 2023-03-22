#include<iostream>
using namespace std ;
int a[105][105];
int n,m;
int vis[105][105];

int dfs(int x,int y){
    if(vis[x][y]) return vis[x][y];
    vis[x][y]=1;
    if(x>1&&a[x][y]>a[x-1][y]) vis[x][y]=max(vis[x][y],dfs(x-1,y)+1);
    if(y>1&&a[x][y]>a[x][y-1]) vis[x][y]=max(vis[x][y],dfs(x,y-1)+1);
    if(x<m&&a[x][y]>a[x+1][y]) vis[x][y]=max(vis[x][y],dfs(x+1,y)+1);
    if(y<n&&a[x][y]>a[x][y+1]) vis[x][y]=max(vis[x][y],dfs(x,y+1)+1);
    return vis[x][y];
}
int main(){
    freopen("in.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans-1;
    return 0;
}