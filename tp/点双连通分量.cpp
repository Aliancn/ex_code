//在用dfs搜索一个割点的过程中就已经完成了对一个子图的访问
//现在只需在访问的过程中将每次访问到的边加入栈中
//当访问到割点的时候将栈中的边弹出
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int maxn = 1e3+5;
vector<int> G[maxn];
int dfn,low[maxn],num[maxn],iscut[maxn];
//点用标号的方式表示
stack <pair<int,int>> edge_satck;
void pop_all(int low){
    while(!edge_satck.empty()){
        pair<int ,int> a=edge_satck.top();
        edge_satck.pop();
        cout<<a.first<<a.second<<endl;
        if(edge_satck.top().first==low) break;
    }
}
void dfs(int u,int fa){
    num[u]=low[u]=dfn++;
    int child=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        edge_satck.push(make_pair(u,v));
        if(!num[v]){
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[u]>=num[u]){//割点的特征即是他的low值大于等于他的num
                iscut[u]=1;
                pop_all(u);
            }
        }
        else if(num[v]<num[u]&&fa!=v){
            low[u]=min(low[u],num[v]);        
        }
    }
    if(u==1&&child>1){
        iscut[u]=1;
        pop_all(u);
    }
}