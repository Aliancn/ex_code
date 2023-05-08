#include<iostream>
using namespace std;
int n,m;                                                                                    
int vis[100000+1000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    int cnt=0;
    vis[n]=vis[m]=1;
    int i=1;
    for( i=1;cnt<=10000;i++){
        if(vis[i]) vis[i+n]=vis[i+m]=1,cnt++;
        else cnt=0;
    }
    cout<<i-10000-2<<endl;
    return 0;
}