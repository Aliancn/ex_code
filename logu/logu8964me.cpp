#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define DP (w!="freopen(\""+q[j]+".out\",\"w\",stdout);")
int T,n,m;
string name[10];
string r,w;

int main (){
    cin>>T>>n>>m;
    for(int i=1;i<=m;i++){
        // scanf("%s",&name[i]);
        cin>>name[i];
    }
    int tag;
    for(int j=0;j<n;j++){
        tag=1;
        for(int i=1;i<=m;i++){
            cin>>r>>w;
            if((r!="freopen(\""+name[i]+".in\",\"r\",stdin);")||(w!="freopen(\""+name[i]+".out\",\"w\",stdout);")){
                if((r.size()>=10)&&(r.substr(0,10)=="//freopen(")&&(r.substr(r.size()-2)==");")
                ||(w.size()>=10)&&(w.substr(0,10)=="//freopen(")&&(w.substr(w.size()-2)==");"))
                   { tag=2;}
                else if(tag==1) tag=3;        
            }
        }
        switch(tag){
            case 1: cout<<"PION2202 RP++."<<endl;break;
            case 2: cout<<"Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI."<<endl;break;
            case 3: cout<<"Good luck and have fun."<<endl;break;
            default: ;
        }
    }
    return 0;
}