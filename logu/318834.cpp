#include<iostream>
using namespace std;
long long  x;
char a[3];
int main(){
    cin>>x>>a[1]>>a[2];
    if((a[1]=='B'&&a[2]!='C')||(a[2]=='B'&&a[1]!='C')){
        cout<<(x*8/10);
    }
    else if((a[1]=='C'&&a[2]!='B')||(a[2]=='C'&&a[1]!='B')){
        cout<<(x*7/10);
    }
    else if((a[1]=='B'&&a[2]=='C')||(a[2]=='B'&&a[1]=='C')){
        cout<<(x*6/10);
    }
    else cout<<x;
    return 0;
}