#include<iostream>
using namespace std;

int nian,yue,ri;

int ans=0;
void check(int x,int y,int z){
    nian=yue=ri=0;
    for(int i=1;i<=4;i++){
        nian+=x%10;
        x/=10;
    }
    for(int i=1;i<=2;i++){
        yue+=y%10;
        y/=10;
    }
    for(int i=1;i<=2;i++){
        ri+=z%10;
        z/=10;
    }
    if(nian==yue+ri) ans++;
}
int main(){
    for(int i=1900;i<=9999;i++){
        for(int j=1;j<=12;j++){
            if(j==1||j==3||j==5||j==7||j==8||j==10||j==12){
                for(int k=1;k<=31;k++){
                    check(i,j,k);
                }
            }
            else if(j==4||j==6||j==9||j==11){
                for(int k=1;k<=20;k++){ 
                    check(i,j,k);
                }
            }
            else if(j==2&&(!(i%400)||(!(i%4)&&i%100))){
                for(int k=1;k<=29;k++){
                    check(i,j,k);
                }
            }
            else {
                for(int k=1;k<=28;k++){
                    check(i,j,k);
                }
            }
        }
    }
    cout<<ans;
}