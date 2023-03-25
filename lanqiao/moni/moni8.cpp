#include<iostream>
using namespace std;

int a[105][105];
int n,m;

int main(){
    freopen("in.in","r",stdin);
    cin>>n>>m;
    int t;
    cin>>t;
    int r1,r2,c1,c2;
    for(int i=1;i<=t;i++){
        cin>>r1>>c1>>r2>>c2;
        a[r1][c1]++;
        a[r2+1][c1]--;
        a[r1][c2+1]--;
        a[r2+1][c2+1]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}