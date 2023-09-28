#include<iostream>
#include<cstring>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

bool check (string a ){
	for (int i=0;i<a.size()/2;i++){	//这里不能取等，，只有一个元素的字符串判是
		if(a[i]!=a[a.size()-1-i]) return 0;
	}
	return 1;
}
#define LOCAL
signed main() {
	#ifdef LOCAL
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	int ans=0;
	cin>>T;
	while(T--) {
		string str ;
		cin>>str;
		if(!check(str))ans = str.size();
		else if (str.size()>1){
			str.pop_back();
			if(!check(str)) ans=str.size();
			else ans =-1;
		}
		else {ans =-1;}
		cout<<ans<<endl;
	}
}