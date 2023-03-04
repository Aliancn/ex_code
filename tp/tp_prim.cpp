#include<iostream>
#include<vector>
#include<queue>
const int maxn= 1e5+5;
using namespace std;

class Edge{
public:
    int to,next;
    int value;
};
struct cmp{
    bool operator()(Edge &a,Edge &b){
        return a.value<b.value;
    }
};
priority_queue<Edge,vector<Edge>,cmp>pri_que;
int head[maxn];
Edge edge[maxn];
int visited[maxn];
int pointCount;

void prim(int n){
    if(pri_que.empty()){
        return ;
    }
    else{
        Edge e=pri_que.top();
        pri_que.pop();
        int index=e.to;
        visited[index]=1;
        for(int i=head[index];i;i=edge[i].next){
            if(edge[i].to!=1){
                pri_que.push(edge[i]);
            }
        }
        prim(index);
    }
}
int check(){
    for(int i=1;i<=pointCount;i++){
        if(visited[i]!=1)return 0;
    }
    return 1;
}
void init (int n){
    for(int i=head[n];i;i=edge[i].next){
        pri_que.push(edge[i]);
    }
}

int main(){
    int edgeCount ;
    cin>>edgeCount;
    for(int i=1;i<=edgeCount;i++){

    }
    
    return 0;
}