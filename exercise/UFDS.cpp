const int maxn =1e5+5;
int fa[maxn];

void init (int n)
{
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

int getfa(int n){
    return fa[n]==n?n:getfa(n);
}
