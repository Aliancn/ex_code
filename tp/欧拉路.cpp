#include<iostream>
using namespace std;
const int maxn = 1e3+5;

int G[maxn][maxn];
int degree[maxn];
int edge_num ;
int vertex_num;
void check(){
    int u,v;
    scanf("%d %d",&u,&v);
    for(int i=1;i<=edge_num;i++){
        degree[u]++;
        degree[v]++;
        G[u][v]++;//可能产生重边
        G[v][u]++;
    }
    for(int i=1;i<=vertex_num;i++){
        if(degree[i]%2)break;//存在奇点，不存在欧拉路
    }
}


void euler (int u){
    int v;
    for(int v=1;v<=vertex_num;v++){//循环所有的邻居点
        if(G[u][v]){
            G[u][v]--;//可能有重边
            G[v][u]--;
            euler(v);
            printf("%d %d\n",u,v);//在这里打印，可以输出完整的欧拉路径
        }
    }
}