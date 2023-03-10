#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e3+5;
vector<int> G[maxn];
int dfn,low[maxn],num[maxn],iscut[maxn];


//起点是dsf(1,-1);
void dfs(int u,int fa){
    num[u]=low[u]=dfn++;
    int child =0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!num[v]){
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=num[u]&&u!=1){//这里判断的是非根节点是否为割点
                iscut[u]=1;          //如果要判断的是割边的话，这里写成(low[u]>num[u] && u!=1)
            }                        //最后统计iscut仍可以得到割边的数量
        }
        else if(num[v]<num[u] && v!=fa){
            low[u]=min(num[v],low[u]);
        }
    }
    if(u==1&&child>1){
        iscut[u]=1;
    }
}