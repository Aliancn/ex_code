#include<iostream>
using namespace std ;

int n=0;
int a[100000+5][3];
int k=0;

bool check(int len){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=(a[i][1]/len)*(a[i][2]/len);
        if(sum>=k) break;
    }
    if(sum>=k) return true;
    return false;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    int l=1,r=100000;
    int mid;
    int ans=0;
    int last_l=0;
    while(l<r){
        last_l=l;
        mid=(l+r)/2;
        if(check(mid)) {
            l=mid;
            if(last_l==l) break;
        }
        else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
    return 0;
}