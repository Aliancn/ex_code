#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;


int a[105][5];
int vis[105][5];
int n=0;
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
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1];
        }
        for(int i=1;i<=n;i++){
            cin>>a[i][2];
        }

        int max1=a[n][1];
        int max2=a[n][2];
        int flag=1;
        for(int i=1;i<n;i++){
            if(a[i][1]<a[i][2]){
                if(a[i][2]<=max1){
                    if(a[i][1]>max2) {
                        flag=0;
                        break;
                    }
                }
                else{
                    if(a[i][2]>max2) {
                        flag=0;
                        break;
                    }
                    else{
                        if(a[i][1]>max1){
                            flag=0;
                            break;
                        }
                    }
                }
            }
            else{
                if(a[i][1]<=max1){
                    if(a[i][2]>max2) {
                        flag=0;
                        break;
                    }
                }
                else{
                    if(a[i][1]>max2) {
                        flag=0;
                        break;
                    }
                    else{
                        if(a[i][2]>max1){
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
	}
}