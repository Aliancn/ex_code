/*
1.键盘不是很熟悉啊
2.使用有限队列时添加queue头
3.使用sqrtl操作浮点数的开方
3.学习手写开方
4.优先队列的排序规则好像不是很清楚
5.间隔判断忽略了正负号，，以后判断相邻要注意
*/
#include <iostream>
using namespace std;
#include<cmath>
#include<queue>

int n;
class aa{
public:
    long long hight;
    int index;
    bool operator < (const aa &x)const{
        if(x.hight!=hight ){
            return hight < x.hight; //从高到低
        }
        else{
            return index<x.index;//从小编号到大编号
        }
    } 
};

long long sqr(long long x){
  long long s=0,l=1,r= 1000000000;
  while(l<=r){
    long long mid =l+r>>1;
    if(mid*mid<=x){
      s=mid;
      l=mid+1;
    }
    else{
      r=mid-1;
    }
  }
  return s;
}

priority_queue<aa> q;
int main()
{
  // 请在此输入您的代码
  cin>>n;
  long long h;
  for(int i=1;i<=n;i++){
    // scanf("%lf",&h);
    cin>>h;
    q.push({h,i});
  }
  int ans=0;
  while (!q.empty()&&q.top().hight!=1){
    aa pre = q.top();
    q.pop();
    while (!q.empty()){
        aa temp = q.top();
        if(temp.hight==pre.hight&& abs(pre.index-temp.index)==1){
            q.pop();
            pre.hight=sqr(pre.hight /2 +1);
            q.push(pre);
            pre=temp;
            continue;
        }
        break;
    }
    pre.hight= sqr(pre.hight/2 +1);
    q.push(pre);
    ans++;
  }
    cout<<ans;
  return 0;
}