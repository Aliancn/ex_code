#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码

  long long  mod = 60*60*1000*24;
  long long  n;
  cin>>n;
  long long  a = n%mod;
  a/=1000;
  int hh,mm,ss;
  ss= a%60;
  a/=60;
  mm=a%60;
  a/=60;
  hh=a%24;
  printf("%02d:%02d:%02d",hh,mm,ss);
  return 0;
}