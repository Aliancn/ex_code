/*
1.不要把=写成==
2.注意当标记会产生覆盖时，要区分优先级
3.
*/



#include<iostream>
using namespace std;

int n;
int _count=0;
int visited[15][15];
int ans[15];
void check(int x,int y){
    int r=y,l=y;
    for(int i=x;i<=n;i++,l--,r++){
        if(visited[i][y]==0){
            visited[i][y]=x;
        }
        if(l>=1&&visited[i][l]==0){
            visited[i][l]=x;
        }
        if(r<=n&&visited[i][r]==0){
            visited[i][r]=x;
        }
    }
}
void uncheck(int x,int y){
    int r=y,l=y;
    for(int i=x;i<=n;i++,r++,l--){
        if(x==visited[i][y]){
            visited[i][y]=0;
        }
        if(l>=1&&x==visited[i][l]){
            visited[i][l]=0;
        }
        if(r<=n&&x==visited[i][r]){
            visited[i][r]=0;
        }
    }
}
void dfs(int r){
    if(r==n+1){
        _count++;
        if(_count<=3){
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(visited[r][i]==0){
            check(r,i);
            ans[r]=i;
            dfs(r+1);
            uncheck(r,i);
        }    
    }
}
int main(){

    cin>>n;
    dfs(1);
    cout<<_count<<endl;

    return 0;
}
