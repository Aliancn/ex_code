//反向建边
//第一次正向深度优先搜索时候，在回溯时，给每个点打上标记，并按标记的位置排列
//标记大的放在后面，则F一定的标记一定是最大的
//因为无论从哪一点开始回溯，F一定是最后被回溯到的
//在反向搜索的时候只要从标号大的开始搜索，一定能找到一个SCC分量

/*
1.这里是有向图，dfs的结构和无向图不同，应该先判断在进入，而不是先进入再判断
*/
#include<iostream>
using namespace std;
#include<vector>

const int maxn = 1e3+5;
vector <int >G[maxn],rG[maxn];
vector<int >S;
int vis[maxn],sccno[maxn],cnt;

//正向搜索并标号
void dfs1(int u){
    if(vis[u])return ;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        dfs1(G[u][i]);
    }
    S.push_back(u);
}

//反向去点
void dfs2(int u){
    if(!sccno[u])return ;
    sccno[u]=cnt;
    for(int i=0;i<rG[u].size();i++){
        dfs2(rG[u][i]);
    }
}

//流程操作
void Kosaraju(int n){
    cnt=0;
    S.clear();
    memset(sccno,0,sizeof(sccno));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dfs1(i);
    for(int i=n-1;i>=0;i--){
        cnt++;
        if(!sccno[S[i]])dfs2(S[i]);
    } 
}
