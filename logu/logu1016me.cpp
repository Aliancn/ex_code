/*
1.使用队列时最好带上empty判断
2.关注每一个变量的改变，，比如这里的剩余油量，，不要忘记减
*/
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
//******************************************
struct Oil{
    double l,cost;
    Oil(double _l,double _cost):l(_l),cost(_cost){}
};
double d1,d2,c;
int n;
double d[10],p[10];
deque<Oil>oil; 
signed main(){
    clock_t cl = clock();
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    //*************************************

    double ans,nowc;
    cin>>d1>>c>>d2>>p[0]>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>p[i];
    }

    d[0]=0;
    d[n+1]=d1;
    oil.push_back(Oil(c,p[0]));
    nowc=c;
    ans+=c*p[0];
    int i=1;

    while (1){

        if(c*d2<d[i]-d[i-1]){
            cout<<"No Solution"<<endl;
            return 0;
        }
        //shaoyou
        double lose_l = (d[i]-d[i-1])/d2;
        nowc-=lose_l;
        while(!oil.empty()){

            Oil temp=oil.front();
            oil.pop_front();
            if(temp.l<lose_l){
                lose_l -= temp.l;
            }
            else{
                temp.l-=lose_l;
                oil.push_front(temp);
                break;
            }
        }
        //panduan 
        if(i==n+1){
            while(!oil.empty()){
                ans-=oil.front().cost*oil.front().l;
                oil.pop_front();
            }
            break;
        }
        //jiayou
        while(!oil.empty()&&oil.back().cost>p[i]){

            ans-=oil.back().cost*oil.back().l;
            nowc-=oil.back().l;
            oil.pop_back();
        }
        ans+=(c-nowc)*p[i];
        oil.push_back(Oil((c-nowc),p[i]));
        nowc=c;
        i++;
    }

    printf("%.2lf",ans);
    //*************************************
end:
    cerr<<"time used: "<<clock()-cl<<" ms "<<endl;
    return 0;
}