#include<iostream>
using namespace std;
const int maxn = 2e5+5;
int a[maxn],b[maxn];
int tt,n;

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    scanf("%d",&tt);
    for(int ii=1;ii<=tt;ii++){
        int zero_num=0;
        int two_flag=0;
        cin>>n;
        
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==0) zero_num++;
            if(a[i]>1) two_flag=1;
        }
        if(zero_num<=(n+1)/2){
            cout<<0<<endl;
        }
        else if(two_flag||zero_num==n){
            cout<<1<<endl;
        }
        else {
            cout<<2<<endl;
        }
    }
    return 0;

}