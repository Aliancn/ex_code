#include<iostream>
using namespace std;

int a[105][105];
int dp[105];
int main(){
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    dp[1]=a[1][1];
    for(int i=2;i<=n;i++){
        // for(int j=1;j<=i;j++)
        //     dp[j]=max(dp[j-1],dp[j])+a[i][j];
        for(int j=i;j>0;j--)
            dp[j]=max(dp[j-1],dp[j])+a[i][j];
    }
    int ans=0;
    if(n%2){
        ans=dp[(n+1)/2];
    }
    else{
        ans=max(dp[n/2],dp[n/2+1]);
    }
    cout<<ans;
    return 0;
}