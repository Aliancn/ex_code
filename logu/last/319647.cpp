#include<iostream>
using namespace std;
int a[105],b[105],c[105],d[105];
int n;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        getchar();
       
        cin>>b[i];
        getchar();
       
        cin>>c[i];
        getchar();
       
        cin>>d[i];
        
    }
    for(int i=1;i<=n;i++){
        if(a[i]==12){
            if(c[i]==12&&b[i]>d[i]){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
        if(a[i]<12){
            if(c[i]<a[i]||(c[i]==12)||(c[i]==a[i]&&d[i]<b[i])){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
    }
    return 0;
}