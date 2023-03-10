/*
1.如果要判断负圈，只用查看能否进行第 n+1 轮即可
*/
#include<iostream>
using namespace std;
const int INF = 1e6;
const int maxn =1e3+5;
struct {
    int u,v,w;
}e[maxn];
int m,n,cnt;
int pre[maxn];

void print_path(int s,int t){
    if(s==t) {printf("%d",s);return ;}
    print_path(s,pre[t]);
    printf("%d ",t);
}

void bellman(){
    int s=1;//定义起点
    int d[maxn];
    for(int k=1;k<=n;k++){
        for(int i=0;i<cnt;i++){
            int x=e[i].u,y=e[i].v;
            if(d[x]>d[y]+e[i].w){
                d[x]=d[y]+e[i].w;
                pre[x]=y;
            }
        }
    }
    //打印操作
}

int main(){
    while(~scanf("%d%d"),&m,&n){
        if(n==0||m==0) return 0;
        cnt=0;
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            e[cnt].u=a,e[cnt].v=b,e[cnt].w=c;cnt++;
            e[cnt].u=b,e[cnt].v=a,e[cnt].w=c;cnt++;
        }
        bellman();      
   }

    return 0;
}