int fa[100000];
//初始化
void reset(){
    for (int i=1;i<=100000;i++){
        fa[i]=i;
    }
}
//查找
int getfa(int x){
    return fa[x]==x?x:getfa(fa[x]);
}
//合并，，后者归为前者
void marge(int x,int y){
    fa[getfa(y)]=getfa(x);
}