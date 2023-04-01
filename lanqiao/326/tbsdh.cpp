#include <iostream>
using namespace std;
int n;
int main()
{
  int ans=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int m=i;
    while(m)
    {
      int k=m%10;
      m=m/10;
      if(k==2 || k==0 || k==1 || k==9){
        ans+=i;
        m=0;//避免像29这种含有两个的重复计算
        }
    }
  }
  cout<<ans<<endl;
  return 0;
}
