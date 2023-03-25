#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

int way1(ll a){
    a-=1;
    if(a%4){
        a=a/4+1;
    }
    else a/=4;
    if(a==0) return 0;
    ll temp=0;
    temp=sqrt(a)+1;
    long long  k=1;
    for( k=max(temp-500,(ll)(1));k<=temp;k++){
        if(k*(k+1)>=a) break;
    }
    // cout<<2*k<<endl;
    return 2*k;
}

int way2(ll a){
    if(a%4){
        a=a/4+1;
    }
    else a/=4;

    ll temp=0;
    temp=sqrt(a)+1;
    long long  k=1;
    for(k=max(temp-500,(ll)(1));k<=temp;k++){
        if(k*k>=a) break;
    }
    return 2*k-1;
}
signed main() {
	#ifdef LOCAL
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		ll a ;
        cin>>a;
        int ans=min(way1(a),way2(a));
        cout<<ans<<endl;
	}
}