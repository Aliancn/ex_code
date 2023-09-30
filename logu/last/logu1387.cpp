/*
1. scanf 记得写&
2. 读入循环的坐标（i，j）不要写错了
*/
#include<bits/stdc++.h>
using namespace std;
//******************************************
int x[105][105];
int f[105][105];
int done[105][105];
int num =0;
int fn(int i,int j){
    // cout<<"num: "<<num++<<endl;
    // cout<<i<<' '<<j<<" "<<f[i][j]<<" "<<x[i][j]<<" "<<done[i][j]<<endl;
    if(done[i][j])return f[i][j];//jian ce guo ,return 
    
    if(i==1||j==1){
        if(x[i][j]==1)
            {
                done[i][j]=1;
                return f[i][j]=1;
            }
        else {
            done[i][j]=1;
            return f[i][j]=0;
            }
    }
    if(x[i][j]==0) {
        done[i][j]=1;
        return f[i][j]=0;
        }
    if(x[i][j]==1){
        f[i][j]=min(min(fn(i-1,j),fn(i,j-1)),fn(i-1,j-1))+1;
        done[i][j]=1;
        return f[i][j];
    }
}
int m,n;
signed main(){
    clock_t cl = clock();
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    //*************************************
    cin>>n>>m;//n hang m ge 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&x[i][j]);
        }
    }
    int ans=0;
    // printf("n:%d m:%d\n",n,m);
    
    for(int i=1;i<=n;i++){
        // cout<<" this is the form:"<<i<<endl;
        for(int j=1;j<=m;j++){
            // cout<<f[i][j]<<" ";
            fn(i,j);
            ans=max(ans,f[i][j]);
        }
        // cout<<endl;
    }
    cout<<ans;
    //*************************************
end:
    cerr<<"time used: "<<clock()-cl<<" ms "<<endl;
    return 0;
}