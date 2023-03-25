#include<iostream>
#include<cstring>
using namespace std;

string _a,_b;
string a[1001],b[1001];
int dp[1000][1000];
int num_a=0,num_b=0;
int main(){
    cin>>_a>>_b;
    for(int i=0;i<_a.length();i++){
        if(_a[i]<='Z') a[++num_a]+=_a[i];
        else a[num_a]+=_a[i];
    }
    for(int i=0;i<_b.length();i++){
        if(_b[i]<='Z') b[++num_b]+=_b[i];
        else b[num_b]+=_b[i];
    }

    for(int i=1;i<=num_a;i++){
        for(int j=1;j<=num_b;j++){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[num_a][num_b];
    
    return 0;
}