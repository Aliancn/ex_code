#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;
int b[200000+5];
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
		int n=0;
        cin>>n;
        for(int i=1;i<n;i++){
            cin>>b[i];
        }
        if(n==2){
            cout<<b[1]<<" "<<b[1]<<endl;
            continue;
        }
        if(b[1]<b[2]){
            cout<<b[1]<<" "<<b[1]<<" ";
            for(int i=2;i<=n-2;i++){
                if(b[i]>b[i+1]){
                    cout<<b[i+1]<<" ";
                }
                else{
                    cout<<b[i]<<" ";
                }
            }
            cout<<b[n-1]<<" ";
            cout<<endl;
        }
        else {
            int i=2;
            cout<<b[1]<<" ";
            int flag=1;
            for(i=2;i<=n-1;i++){
                if(flag&&i<=n-2&&b[i]<b[i+1]){
                    cout<<b[i]<<" ";
                    flag=0;
                }
                if(flag&&i==n-1){
                    cout<<b[n-1]<<" ";
                }
                if(!flag&&i<=n-2){
                    if(b[i]>b[i+1]){
                        cout<<b[i+1]<<" ";
                        continue;
                    }
                }
                cout<<b[i]<<" ";
            }
            cout<<endl;
        }

	}
}