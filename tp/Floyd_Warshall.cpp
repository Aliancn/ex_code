/*
1.值得注意的是，必须将k循环写在ij循环的外面
  Floyd算法的核心在于，将路径分为过K点和不过K点的两个部分
  而且每次优化路径之后会对下次的优化操作产生影响
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e6;
const int maxn =1e3+5;
int n,m;
int graph[maxn][maxn];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(graph[i][k]==INF) continue;
            for(int j=1;j<=n;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j])
                graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }
}

int main(){
    while(!scanf("%d %d"),&n,&m);
    if(n==0 && m==0) return 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[i][j]=INF;            
        }
    }
    while (m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a][b]=graph[b][a]=c;
    }
    floyd();
    return 0;
}