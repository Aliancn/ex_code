#include<iostream>

using namespace std;
const int maxn = 2*1e5+10;
const int INF = 1e9+100;
int a[maxn],c[maxn];
void sol(){
	int n;
	cin>>n;
	int c_min = INF ;
	int pos =0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if (c[i]<=c_min){
			c_min = c[i];
			pos = i;
		}
	}
	int k=0;
	cin>>k;
	if (k<c_min){
		for(int i=1;i<=n;i++){
			cout<<0<<" ";
		}
		cout<<endl;
		return;
	}

	int yu = k;
	int last = 0;
	int last_min = 0;
	int now_min = c_min;
	int pr_last =0 ;
	while(yu){
		int tmp = yu/(now_min-last_min);
		if (tmp == 0) break;
		for(int i=last+1; i<=pos;i++){
			cout<< tmp <<" ";
		}
		pr_last = pos;
		yu = yu % (now_min - last_min);
		last = pos;
		last_min = now_min;
		now_min = INF ;
		for(int i= pos+1 ;i<=n;i++){
			if (c[i]<= now_min ){
				now_min = c[i];
				pos = i ;
			}
		}
		if (pos == n) break;
	}
	for(int i= pr_last +1 ;i<=n;i++){
		cout<<0<<" ";
	}
	cout<<endl;
	return ;
	

}

int main(){

	int t ;
	cin>>t ;
	while(t--){
		sol();
	}
	return 0;
}