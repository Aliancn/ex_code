#include<iostream>
#include<climits>
using namespace std;

int a[105][105];
int x[]={-3,-2,-2,-1,-1,-1,0,0,0};
int y[]={0,-1,0,-2,-1,0,-3,-2,-1};
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int trans=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            trans=INT_MIN;
            for(int k=0;k<9;k++){
                if(i+x[k]>0&&j+y[k]>0){
                    trans=max(trans,a[i+x[k]][j+y[k]]);
                }
            }
            if(trans!=INT_MIN) a[i][j]+=trans;
        }
    }
    cout<<a[n][m];
    return 0;
}