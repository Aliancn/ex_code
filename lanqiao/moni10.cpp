#include<iostream>
using namespace std;
int a[1000000+5];
int k;
int kmin[1000000+5];

int my_min(int x,int y){
    if(x>y) return y;
    else return x;
}

int main(){
    freopen("in.in","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        kmin[i]=a[i];    
    }
    cin>>k;
    
    for(int i=1;i<=n-k+1;i++){
        for(int j=i;j<i+k&&j<=n;j++)
            kmin[i]=my_min(kmin[i],kmin[j]);
    }
    for(int i=1;i<=n;i++){
        cout<<my_min(my_min(a[i],kmin[my_min(n,i+1)]),kmin[max(1,i-k)])<<" ";
    }
    return 0;
}