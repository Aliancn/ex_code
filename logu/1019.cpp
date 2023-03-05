/*
1.包含最小重叠的判断
2.注意使用次数的标记和判断，，比如从零开始记录，不超过两次，则use>=2就continue；
*/
#include<bits/stdc++.h>
using namespace std;
//******************************************
#define LOCAL
string str[25], sta;
int length=0;
int use[25];
int n=0;

int overlap(const string &a,const string &b){//判断字符最小重叠,不能重合
    for(int i=1;i<min(a.length(),b.length());i++){
        int flag=1;
        for(int j=0;j<i;j++){ 
            if(a[a.length()-i+j]!=b[j])flag=0;
        }
        if(flag)return i;//注意这里放在检测循环的外面
    }
    return 0;
}


void dfs(string strnow,int lengthnow){
    length=max(length,lengthnow);
    for(int i=1;i<=n;i++){
        if(use[i]>=2)continue;//注意：这里的use表示用过的次数，注意边界值
        if(int c = overlap(strnow,str[i])){
            use[i]++;
            // strnow=strnow+str[i];
            // dfs(strnow,lengthnow+str[i].length()-c);
            dfs(str[i],lengthnow+str[i].length()-c);
            use[i]--;
        }
    }
}
signed main(){
    clock_t cl = clock();
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    //*************************************

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i];
    }
    cin>>sta;
    dfs(' '+sta,1);
    cout<<length;
    //*************************************
end:
    cerr<<"time used: "<<clock()-cl<<" ms "<<endl;
    return 0;
}