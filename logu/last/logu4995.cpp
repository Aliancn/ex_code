/*笔记
1.大数记得要开longlong
2.注意点的消除是在哪一步，，这里考虑两边的点一起消还是一次只消一边
*/
#include<bits/stdc++.h>
using namespace std;
//******************************************
signed main(){
    clock_t cl = clock();
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    /*************************************/
    int h[305];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    h[0]=0;
    sort(h+1,h+n+1);   
    int l=1,r=n;
    long long ans=h[n]*h[n];
    bool isunder = false;
    while(l<r){
        if(isunder){
            ans+=(h[l]-h[r])*(h[l]-h[r]);
            l++;
            isunder=!isunder;
        }
        else{
            ans+=(h[l]-h[r])*(h[l]-h[r]);
            r--;
            isunder=!isunder;
        }
    }
    cout<<"ok"<<endl;
    cout<<ans;

    /*************************************/
end:
    cerr<<"time used: "<<clock()-cl<<" ms "<<endl;
    return 0;
}