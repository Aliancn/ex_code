#include<iostream>
#include<algorithm>
using namespace std;

int n;
// const int maxn = 1e5+5;
const int maxn = 15;
int A[maxn],B[maxn],C[maxn];
int up(int *a,int num){
    int l=1,r=n;
    int mid;
    while(l<r){
        mid=(l+r)/2;
        if(a[mid]<=num) l=mid+1;
        if(a[mid]>num) r=mid;
    }
    if(a[l]<=num) return 0;
    while(a[l-1]==a[l]){
        l--;
    }
    return l;
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>n;
    for(int j=1;j<=n;j++){
        cin>>A[j];
    }
    for(int j=1;j<=n;j++){
        cin>>B[j];
    }
    for(int j=1;j<=n;j++){
        cin>>C[j];
    }
    sort(A+1,A+1+n);
    sort(B+1,B+1+n);
    sort(C+1,C+1+n);

    int ans=0;
    int num1,num2;
    int tt=0,kk=0;
    for(int i=1;i<=n;i+=tt){
        tt=0;
        for(int j=i;j<=n;j++){
            if(A[i]==A[j]) tt++;
            else break;
        }
        num1=up(B,A[i]);
        if(num1==0) break;
        for(int k=num1;k<=n;k+=kk){
            kk=0;
            for(int j=k;j<=n;j++){
                if(B[j]==B[k]) kk++;
                else break;
            }
            num2=up(C,B[k]);
            if(num2==0) break;
            ans+=tt*kk*(n-num2+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}