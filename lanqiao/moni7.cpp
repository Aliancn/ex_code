#include<iostream>
#include<cmath>
using namespace std;

int W,H ,n,R;
int x[105],y[105]; 
bool check(int i,int j){
    for(int k=1;k<=n;k++){
        if(pow(i-x[k],2)+pow(j-y[k],2)<=pow(R,2)) return true;
    }
    return  false;
}

int main(){
    freopen("in.in","r",stdin);
    int ans=0;
    cin>>W>>H>>n>>R;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<=W;i++){
        for(int j=0;j<=H;j++){
            if(check(i,j)) ans++;
        }
    }
    cout<<ans;
}