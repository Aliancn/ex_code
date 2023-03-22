#include<iostream>
#include<algorithm>
using namespace std;

int n;
// const int maxn = 1e5+5;
const int maxn = 15;
int A[maxn],B[maxn],C[maxn];
long long ans;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>n;
    for(int j=1;j<=n;j++){
        cin>>A[j];
    }
    // for(int j=1;j<=n;j++){
    //     cin>>B[j];
    // }
    // for(int j=1;j<=n;j++){
    //     cin>>C[j];
    // }
    sort(A+1,A+1+n);
    // sort(B+1,B+1+n);
    // sort(C+1,C+1+n);

    // for(int i=1;i<=n;i++){
    //     int x=lower_bound(A+1,A+n+1,B[i])-(A+1);
    //     int y=n-(upper_bound(C+1,C+n+1,B[i])-(C+1));
    //     ans+=x*y;
    // }
    int x=lower_bound(A+1,A+n+1,1)-(A+1);
    cout<<x<<endl;
    int y=upper_bound(A+1,A+n+1,1)-(A+1);
    cout<<y;




    return 0;
}