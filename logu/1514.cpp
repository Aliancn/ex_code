#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
int aa[600][600];
int vis[600][600];
int ll[600][600];
int rr[600][600];

// struct node{
//     int x,y;
// };
// queue<node> q;

struct line
{
    int l=600,r;
} lline[600];
int num_line=0;
bool cmp(line a,line b){
    if(a.l!=b.l)
        return a.l<b.l;
    return a.r<b.r;
}

int dx[]={1,0,-1,0 };
int dy[]={0,1,0,-1 };

void dfs(int x,int y){
    vis[x][y]=1;
    int tx,ty;
    for(int i=0;i<=4;i++){
        tx=x+dx[i];
        ty=y+dy[i];
        if(tx<1||tx>n||ty<1||ty>m||aa[x][y]<=aa[tx][ty]) continue;
        if(vis[tx][ty] ) {
            // lline[num_line].l=min(ll[tx][ty],lline[num_line].l);
            // lline[num_line].r=max(rr[tx][ty],lline[num_line].r);
            ll[x][y]=min(ll[x][y],ll[tx][ty]);
            rr[x][y]=max(rr[x][y],rr[tx][ty]);
            continue;
        }
        else {                   
            dfs(tx,ty);
            ll[x][y]=min(ll[x][y],ll[tx][ty]);
            rr[x][y]=max(rr[x][y],rr[tx][ty]);
            
        }
    }
    if(x==1){
        lline[num_line].l=min(ll[x][y],lline[num_line].l);
        lline[num_line].r=max(rr[x][y],lline[num_line].r);
    }
}

void ans(){
    // int dl,dr;
    // for(int i=1;i<=m;i++){
    //     lline[i].l=lline[i].r=dl=dr=i;
    //     while(dl>1){
    //         if(aa[n][dl-1]<aa[n][dl]) lline[i].l = (--dl);
    //         if(aa[n][dl-1]>=aa[n][dl]) break;
    //     }
    //     while(dr<m){
    //         if(aa[n][dr]>aa[n][dr+1]) lline[i].r = (++dr);
    //         if(aa[n][dr]<=aa[n][dr+1]) break;
    //     }
    // }
    sort(lline+1,lline+num_line+1,cmp);
    int num=0;
    int i=1;
    int now_pos=1;
    int nex_pos=1;
    while(now_pos<=m){
        while(lline[i].l<=now_pos){
            nex_pos=max(nex_pos,lline[i].r);
            i++;
        }
        now_pos=nex_pos+1;
        num++;
    }
    cout<<1<<endl;
    cout<<num<<endl;
}

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cin>>aa[i][j];
            scanf("%d",&aa[i][j]);
        }
    }
    memset(ll,0x3f,sizeof(ll));
    for(int i=1;i<=m;i++){
        ll[n][i]=rr[n][i]=i;
    }
    for(int i=1;i<=m;i++){
        if(!vis[1][i]) {
            num_line++;
            dfs(1,i);
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(vis[n][i]==0) cnt++;
    }
    if(cnt){
        cout<<0<<endl;
        cout<<cnt;
    }
    else{
        ans();
    }
    return 0;
}
