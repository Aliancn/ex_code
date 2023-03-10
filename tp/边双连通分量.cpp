//先求出变双连通分量
//在对low值进行统计求出缩点后的树 
//统计度数为 1 的节点个数 N 
//最后计算的添加边数== (N+1) / 2
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int maxn = 1e3+5;
int vertex_num;
vector<int> G[maxn];
int dfn,low[maxn],num[maxn];
pair<int ,int >iscutdege[maxn];
int cutedge_num ;
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
            if(low[v]>num[u]&&u!=1){//这里判断的是非根节点是否为割点
                iscutdege[++cutedge_num]=make_pair(u,v);          //如果要判断的是割边的话，这里写成(low[u]>num[u] && u!=1)
            }                        //此时的割边为（u,v）   感觉这里的标记没有什么用
        }
        else if(num[v]<num[u] && v!=fa){
            low[u]=min(num[v],low[u]);
        }
    }
}

//重新建树（并查集）
int fa[maxn];
void init(){
    for(int i=1;i<=vertex_num;i++){
        fa[i]=low[i];//把每个边连通分量中的点全部归为同一点
    }
}

int degree[maxn];
int visited[maxn];
int needed_sum(){
    init();
    for(int i=1;i<=cutedge_num;i++){
        pair<int ,int> a = iscutdege[i];
        degree[fa[a.first]]++;
        degree[fa[a.second]]++;
    }
    int n=0;
    for(int i=1;i<=cutedge_num;i++){
        pair<int ,int >a =iscutdege[i];
        if(!visited[a.first]&&degree[fa[a.first]]<2){
            n++;
        }
        if(!visited[a.second]&&degree[fa[a.second]]<2){
            n++;
        }
    }
    return ( n + 1 ) / 2;
}