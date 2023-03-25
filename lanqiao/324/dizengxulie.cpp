#include<iostream>
using namespace std;

char a[50][60];


int cal(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    int ans=1;
    for(int i=n;i>=n-1;i--){
        ans*=i;
    }
    return ans / 2;
}


int hang(int x,int y){
    int hang_num=0;
    for(int i=y+1;i<=50;i++){
        if(a[x][i]>a[x][y]) hang_num++; 
    }
    return hang_num;
}
int lie(int x,int y){
    int lie_num=0;
    for(int j=x+1;j<=30;j++){
        if(a[j][y]>a[x][y]) lie_num++;
    }
    return lie_num;
}

int xie(int x,int y){
    int xie_num=0;
    int tx=x+1,ty=y+1;
    while(tx<=30&&ty<=50){
        if(a[tx][ty]>a[x][y]) xie_num++;
        tx++;
        ty++;
    }
    tx=x+1;
    ty=y-1;
    while(tx<=30&&ty>0){
        if(a[tx][ty]!=a[x][y]) xie_num++;
        tx++;
        ty--;
    }
    return xie_num;
}

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    for(int i=1;i<=30;i++){
        for(int j=1;j<=50;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=30;i++){
        for(int j=1;j<=50;j++){
            ans+=hang(i,j);
            ans+=lie(i,j);
            ans+=xie(i,j);
        }

    }
    cout<<ans;
    return 0;
}