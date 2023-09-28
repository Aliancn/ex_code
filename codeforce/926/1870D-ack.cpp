#include<iostream>

using namespace std;
const int maxn = 2*1e5+10;
const int INF = 1e9+100;

int a[maxn],c[maxn];
void sol(){
	int n =0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int k=0;
	cin>>k;
	for(int i=n-1;i>=1;i--){
		c[i] = min(c[i],c[i+1]);
	}
	int out=k;
	for(int i=1;i<=n;i++){
		int add = c[i] - c[i-1];
		out = min(add ? k/add:out,out);
		k -= add * out;
		cout<<out<<" ";
	}
	cout<<endl;
}

int main(){
	int t=0;
	cin>>t;
	while(t--) sol();
	return 0;
}