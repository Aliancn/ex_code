#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

int a[maxn];
signed main() {
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
        memset(a,0,sizeof(a));
		int n,q;
        cin>>n>>q;
        int temp=0;
        a[0]=0;
        for(int i=1;i<=n;i++){
            // scanf("%d",&temp);
            cin>>temp;
            if(temp%2) a[i]=a[i-1]+1;
            else a[i]=a[i-1];
        }

        int l,r,k;
        int ans=0;
        for(int i=1;i<=q;i++){
            cin>>l>>r>>k;
            if(k%2){
                ans=a[l-1]+(r-l+1)+a[n]-a[r];
            }
            else{
                ans=a[l-1]+a[n]-a[r];
            }
            // cout<<"ans : "<<ans<<endl;
            if(ans%2){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
	}
}