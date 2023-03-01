#include<algorithm>
#include<iostream>
using namespace std;

class Edge {
    public:
    int toVertex,fromVertex;
    int next;
    int LCA;
    Edge(): toVertex(-1),fromVertex(-1),next(-1),LCA(-1){}
    Edge(int u,int v,int n):fromVertex(u), toVertex(v), next(n), LCA(-1){}
};

const int maxn = 100;
int head[maxn],queryHead[maxn];
Edge edge[maxn],queryEdge[maxn];
int parent[maxn],visited[maxn];
int vertexConunt,edgeCount,queryCount;


void init (){
    for(int i=0;i<=vertexConunt;i++){
        parent[i]=i;
    }
}
int find(int x){
    return parent[x]==x?x:find(x);
}

void tarjan(int u){
    parent[u]=u;
    visited[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        Edge & e=edge[i];
        if(!visited[e.toVertex]){ 
            tarjan(e.toVertex);
            parent[e.toVertex]=u;
        }
    }
    for(int i=queryHead[u];i!=-1;i=queryEdge[i].next){
        Edge &e =queryEdge[i];
        if(visited[e.toVertex]){
            queryEdge[i^1]=e.LCA=find(e.toVertex);
        }
    }

}