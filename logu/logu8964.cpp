#include<bits/stdc++.h>
#define PD (r!="freopen(\""+q[j]+".in\",\"r\",stdin);")||(w!="freopen(\""+q[j]+".out\",\"w\",stdout);")
using namespace std;
int main(){
    int t,n,m,ren;
    string q[5],r,w;
    cin>>t>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i];
    }
    for(int i=1;i<=n;i++){
        ren=1;
        for(int j=1;j<=m;j++){
            cin>>r>>w;
            if((r.size()>=10&&r.substr(0,10)=="//freopen("&&r.substr(r.size()-2)==");")||(w.size()>=10&&w.substr(0,10)=="//freopen("&&w.substr(w.size()-2)==");")){
                ren=3;//见祖宗人判断
            }
            else if(PD==1){//乐子人判断
                ren=max(ren,2);
                //cout<<PD;
            }
        }
        if(ren==1){//普通人
            cout<<"PION2202 RP++."<<endl;
        }
        else if(ren==2){//乐子人
            cout<<"Good luck and have fun."<<endl;
        }
        else{//见祖宗人
            cout<<"Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI."<<endl;
        }
    }

    return 0;
}