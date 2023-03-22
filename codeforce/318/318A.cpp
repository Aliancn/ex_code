#include<iostream>
using namespace std;
int t;
int a,b,c,d;

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c>>d;
        int temp=0;
        if(d<b){
            cout<<-1<<endl;
            continue;
        } 
        if(d==b){
            if(a>=c){
                temp=a-c;
                cout<<temp<<endl;
                continue;
            }
            else {
                cout<<-1<<endl;
                continue;
            }
        }
        if(d>b){
            temp=d-b;
            a+=temp;
            if(a>=c) {
                temp+=a-c;
                cout<<temp<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
    }
    return 0;
}
