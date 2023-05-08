#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

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
		int n;
        int x1,x2,y1,y2;
        cin>>n>>x1>>y1>>x2>>y2;
        int cen = n/2;
        if(x1>cen) x1=n-x1+1;
        if(x2>cen) x2=n-x2+1;
        if(y1>cen) y1=n-y1+1;
        if(y2>cen) y2=n-y2+1;
        int ans =abs(max (cen -x1,cen -y1)-max(cen -x2,cen-y2));
        cout<<ans <<endl;
	}
}