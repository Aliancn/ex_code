#include<istream>
#include<stack>
#include<vector>
using namespace std;
const int maxn = 1e3+5;
int low[maxn],num[maxn],dfn;
int sccno[maxn];
stack <int > S;
vector<int > G[maxn];
int cnt;
void dfs(int u){
    S.push(u);
    num[u]=low[u]=++dfn;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v]) low[u]=min(num[v],low[u]);//处理回退边
    }
    if(low[u]==num[u]){
        cnt++;
        while(!S.empty()){
            int v=S.top();
            S.pop();
            sccno[v]=cnt;
            if(v==u) break;
        }
    }
}

void tarjan(int n){
    cnt=dfn=0;
    memset(sccno,0,sizeof(sccno));
    memset(low,0,sizeof(low));
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++){
        if(!num[i]) dfs(i);
    }
}