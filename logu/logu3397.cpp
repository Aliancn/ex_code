#include<bits/stdc++.h>
using namespace std;
//*****************************************
const int maxn =1000+5;
int m,n;
int dif[maxn][maxn],num[maxn][maxn];
int ans=0;
void add(int x1,int y1,int x2,int y2,int c){
    dif[x1][y1]+=c;
    dif[x2+1][y1]-=c;
    dif[x1][y2+1]-=c;
    dif[x2+1][y2+1]+=c;
}
void rebuild(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+dif[i][j];
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main(){
    clock_t cl = clock();
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    //*************************************
    cin>>n>>m;
    int x1,y1,x2,y2;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        add(x1,y1,x2,y2,1);
    }
    rebuild();
    //*************************************
end:
    cerr<<"time used: "<<clock()-cl<<" ms "<<endl;
    return 0;
}