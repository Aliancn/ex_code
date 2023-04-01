#include<bits/stdc++.h>

using namespace std;

#define maxn 2010

#define maxm 10010

int n,m,w[maxn],v[maxn],k;

int dp[maxn][maxm][2];//dp[i][j][0]：还没有使用魔法；dp[j][1]：已经使用魔法了

int main(){

    scanf("%d%d%d",&n,&m,&k);

    for(int i=1;i<=n;i++){

        scanf("%d%d",&w[i],&v[i]);

    }

    for(int i=1;i<=n;i++){

        for(int j=0;j<w[i];j++){//最开始错是因为j从1开始循环了，这一题w[i]可以取0，所以dp[i][0][0/1]不总是0，要被更新

            dp[i][j][0]=dp[i-1][j][0];

            dp[i][j][1]=dp[i-1][j][1];

        }

        for(int j=w[i];j<=m;j++){

            dp[i][j][0]=max(dp[i-1][j-w[i]][0]+v[i],dp[i-1][j][0]);

            dp[i][j][1]=max(dp[i-1][j-w[i]][1]+v[i],dp[i-1][j][1]);

            if(j>=w[i]+k)dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k-w[i]][0]+2*v[i]);

        }

    }

    /* for(int i=1;i<=n;i++){//这种是压缩的写法

        for(int j=m;j>=w[i];j--){

            dp[j][0]=max(dp[j-w[i]][0]+v[i],dp[j][0]);

            dp[j][1]=max(dp[j-w[i]][1]+v[i],dp[j][1]);

            if(j>=w[i]+k)dp[j][1]=max(dp[j][1],dp[j-k-w[i]][0]+2*v[i]);

        }

    } */

    printf("%d",max(dp[n][m][0],dp[n][m][1]));

    system("pause");

    return 0;

}

