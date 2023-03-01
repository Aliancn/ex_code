#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MAXN 50007
using namespace std;
vector <int> v[MAXN];
vector <int> w[MAXN];
//这里v用来存边
//这里w用来存每条边的权值
int fa[MAXN][31],cost[MAXN][31],dep[MAXN];
//fa 表示祖先  cost 表示花费  dep 表示深度
int n,m ;
int a,b,c;

void dfs(int root,int father){
    fa[root][0]=father;
    dep[root]=dep[fa[root][0]]+1;
    for(int i=1;i<31;i++){
        fa[root][i]=fa[fa[root][i-1]][i-1];//第2^i个祖先，是第2^i-1的祖先的2^i-1个祖先
        cost[root][i]=cost[fa[root][i-1]][i-1]+cost[root][i-1];
    }
    int sz=v[root].size();
    for(int i=0;i<sz;i++){
        if(v[root][i]==father)continue;
        cost[v[root][i]][0]=w[root][i];
        //v[root][i]指向root点的第i个子节点
        //cost[v[root][i]][0]表示root的第i个子节点到他的第一个父节点的cost花费
        //w[root][i]记载root到第i个节点的花费
        dfs(v[root][i],root);
    }
}
int ans=0;
int lca(int x,int y){
    if(dep[x]>dep[y]){
        swap(x,y);
    }
    int tmp =dep[y]-dep[x];
    for(int j=0;tmp;j++,tmp>>1){
        if(tmp&1){
            ans+=cost[y][j];
            y=fa[y][j];
        }
    }
    if(y==x){
        return ans;
    }
    //找到第一个不是他们祖先的两个点
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


signed main(){
     memset(fa ,0, sizeof(fa));
     memset(cost,0,sizeof(cost));
     memset(dep,0,sizeof(dep));
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
        scanf("%d %d %d",a,b,c);
        a++,b++;//调整点的序号，从1 开始计算
        v[a].push_back(b);
        v[b].push_back(a);//建立双向图
        w[a].push_back(c);
        w[b].push_back(c);//
     }
    dfs(1,0);
    cin>>m;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        a++;
        b++;
        printf("%d\n",lca(a,b));
    }
    return 0; 
}