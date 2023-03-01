#include<iostream>
#include<vector>
using namespace std;

#define maxn 100005
vector<int> v[maxn];
vector<int> w[maxn];
int fa[maxn][31],cost[maxn][31],dep[maxn];
int n,m;
int a,b,c;

void dfs(int root,int father){
    //初始化第一个父节点
    fa[root][0]=father;
    dep[root]=dep[fa[root][0]]+1;
    for(int i=1;i<31;i++){
        fa[root][i]=fa[fa[root][i-1]][i-1];
        cost[root][i-1]=cost[fa[root][i-1]][i-1]+cost[root][i-1];
    }
    int sz=v[root].size();
    for(int i=0;i<sz;i++){
        if(v[root][i]==father)continue;
        cost[v[root][i]][0]=w[root][i];
        dfs(v[root][i],root);
    }
}
int ans=0;
int lca(int x,int y){
    if(dep[x]>dep[y]){
        swap(x,y);
    }
    int temp=dep[y]-dep[x];
    for(int j=0;temp;j++,temp>>1){
        if(temp&1){
            ans+=cost[y][j];
            y=fa[y][j];
        }
    }
    if(x==y){
        return ans;
    }
    for(int j=30;j>=0&&y!=x;j--){
        if(fa[x][j]!=fa[y][j]){
            ans+=cost[x][j]+cost[y][j];
            x=fa[x][j];
            y=fa[y][j];
        }
    }
    ans+=cost[x][0]+cost[y][0];
    return ans;
}

int main(){
    memset(fa,0,sizeof(fa));
    memset(cost,0,sizeof(cost));
    memset(dep,0,sizeof(dep));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        a++,b++;
        v[a].push_back(b);
        v[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }\
    dfs(1,0);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a++,b++;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}