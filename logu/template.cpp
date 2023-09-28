#include<iostream>
#define Local
using namespace std;

void sol(){

}

int main(){
    #ifdef Local
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif

    int t =1 ;
    cin>>t;
    while (t--)
    {
        sol();
    }
    return 0;
}