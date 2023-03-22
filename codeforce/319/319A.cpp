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
		int a,b,c;
        cin>>a>>b>>c;
        if(a+b==c){
            cout<<'+'<<endl;
        }
        else cout<<'-'<<endl;

	}
}