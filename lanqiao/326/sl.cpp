#include<iostream>
using namespace std;


int n,m;
int a[1000][1000];
int vis[1000][1000];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
int main(){
    int temp;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>temp;
            if(temp) a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                vis[i][j]=9;
            }
            else{
                int num=0;
                for(int k=0;k<8;k++){
                    int tx=i+dx[k];
                    int ty=j+dy[k];
                    if(tx<1||tx>n||ty<1||ty>m) continue;
                    if(a[tx][ty]==1) num++;
                }
                vis[i][j]=num;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<vis[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}

