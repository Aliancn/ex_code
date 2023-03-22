#include<iostream>
#include<string >
using namespace std;

string a;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t=0;
    cin>>t;
    getchar();
    while(t--){
    getline(cin,a);
    int aa[4];
    int bb[4];
    int tt=0;
    int ddes1[4],ddes2[4];
    aa[1]=(int(a[0])-48)*10+int(a[1])-48;
    aa[2]=(int(a[3])-48)*10+int(a[4])-48;
    aa[3]=(int(a[6])-48)*10+int(a[7])-48;
    bb[1]=(int(a[9])-48)*10+int(a[10])-48;
    bb[2]=(int(a[12])-48)*10+int(a[13])-48;
    bb[3]=(int(a[15])-48)*10+int(a[16])-48;
    if(a.length()>17) tt=(int)a[20]-48;
    for(int i=1;i<=3;i++){
        ddes1[i]=bb[i]-aa[i];
    }
    ddes1[1]=ddes1[1]+tt*24;

    getline(cin,a);
    tt=0;
    aa[1]=(int(a[0])-48)*10+int(a[1])-48;
    aa[2]=(int(a[3])-48)*10+int(a[4])-48;
    aa[3]=(int(a[6])-48)*10+int(a[7])-48;
    bb[1]=(int(a[9])-48)*10+int(a[10])-48;
    bb[2]=(int(a[12])-48)*10+int(a[13])-48;
    bb[3]=(int(a[15])-48)*10+int(a[16])-48;
    if(a.length()>17) tt=(int)a[20]-48;
    for(int i=1;i<=3;i++){
        ddes2[i]=bb[i]-aa[i];
    }
    ddes2[1]=ddes2[1]+tt*24;
   
    for(int i=1;i<=3;i++){
        ddes1[i]=ddes1[i]+ddes2[i];
        if(ddes1[i]%2){
            ddes1[i]--;
            ddes1[i+1]+=60;
        }
    }
    int cc=0;
    for(int i=3;i>=1;i--){
        ddes1[i]=(ddes1[i])/2+cc;
        if(ddes1[i]<0) cc=-1+(ddes1[i]/61);
        if(ddes1[i]>0) cc=(ddes1[i]/60);
        ddes1[i]=(ddes1[i]+120)%60;  
    }
    printf("%02d:%02d:%02d\n",ddes1[1],ddes1[2],ddes1[3]);
    }
    
    return 0;
}