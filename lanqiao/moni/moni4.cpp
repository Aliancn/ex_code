#include<iostream>
using namespace std;
int num[40];
int ans=0;
int main(){
    freopen("in.in","r",stdin);
    for(int i=1;i<=30;i++){
        cin>>num[i];
    }
    for(int i=1;i<30;i++){
        for(int j=i+1;j<=30;j++){
            if(num[i]*num[j]>=2022) ans++;
        }
    }
    cout<<ans;
    return 0;
}