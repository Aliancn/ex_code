#include<iostream>
#include<cstring>
using namespace std;

int aa[200][200];
int vis[200][200];
int last_step[200][200];
int n,m,t;
int x1,x2,y1,y2;
int ans=0;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void dfs(int x,int y,int now_step){
    vis[x][y]=1;
    if(x==x2&&y==y2&&now_step==t) {
        last_step[x][y]=0;
        ans++;
        return ;
    }
    if(now_step>=t) return ;
    int ty,tx;
    for(int i=0;i<4;i++){
        tx=x+dx[i];
        ty=y+dy[i];
        if(tx<1||tx>n||ty<1||ty>m||aa[tx][ty]==0) continue;
        if(vis[tx][ty]){
            if(now_step+last_step[tx][ty]+1==t) {
                ans++;
                continue;
            }
        }
        else{
            dfs(tx,ty,now_step+1);
            last_step[x][y]=min(last_step[x][y],last_step[tx][ty]+1);
        }
    }
    
}

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    memset(last_step,0x3f,sizeof(last_step));
    char temp;
    cin>>n>>m>>t;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>temp;
            if(temp=='.'){
                aa[i][j]=1;
            }
            else{
                aa[i][j]=0;
            }
        }
    }
    cin>>x1>>y1>>x2>>y2;

    dfs(x1,y1,0);
    cout<<ans;
    return 0;
}
