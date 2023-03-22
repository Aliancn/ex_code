#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;


signed main() {
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n=0;
		cin>>n;
		int now,m=0,b=0;
		for(int i=1;i<=n;i++){
			cin>>now;
			if(now%2){
				b+=now;
			}
			else{
				m+=now;
			}
		}
		if(m>b){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}