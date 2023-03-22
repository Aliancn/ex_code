#include<iostream>
using namespace std;
int n=0;
int now=0;
int main(){
    cin>>now>>n;
    int ans = (now+n)%7;
    if(ans>0) cout<<ans;
    else cout<<7;
    return 0;
}