#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
const int N=1300;
struct node{
	int s,a,e;
}p[N];
bool cmp(node a,node b)
{
	return (a.a+a.e+a.s)<(b.a+b.e+b.s);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&p[i].s,&p[i].a,&p[i].e);
	sort(p+1,p+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=(n-i)*(p[i].a+p[i].e+p[i].s)+p[i].a+p[i].s;
	cout<<ans;
	return 0;
}