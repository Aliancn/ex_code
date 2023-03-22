#include<iostream>
using namespace std;
long long a[3];
int T;
int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>a[1]>>a[2];
        int k=1;
        while (a[1]!=0&&a[2]!=0)
        {            
            if(a[k]<a[3-k]){
                a[k]++;
            }
            else{
                a[k]/=2;
            }
            k=3-k;
        }
        cout<<a[1]<<" "<<a[2]<<endl;
    }
    return 0;
}