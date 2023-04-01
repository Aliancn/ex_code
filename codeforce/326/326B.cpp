#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;


const int inf=0x3f3f3f3f;

const int maxn =50000+5;
int m;
int n[maxn],vis[maxn];
vector<int >a[maxn];
int win[maxn];
int findsu=0;
void dfs(int day){
    if(day==m+1) { findsu=1;return ;}
    for(int i=0;i<n[day];i++){
        if(vis[a[day][i]] ) return ;
    }
    for(int i=0;i<n[day];i++){
        if(vis[a[day][i]]) continue;
        else{
            vis[a[day][i]]=1;
            win[day]=a[day][i];
            dfs(day+1);
            if(findsu==1) return ;
            vis[a[day][i]]=0;
        }
    }
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
        memset(n,0,sizeof(n));
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        memset(win,0,sizeof(win));
        findsu=0;
        cin>>m;
        int i=0;
		for( i=1;i<=m;i++){
            cin>>n[i];
            int temp=0;
            for(int j=1;j<=n[i];j++){
                cin>>temp;
                a[i].push_back(temp);
            }
        }
        dfs(1);
        if(findsu){
            for(int i=1;i<=m;i++){
                cout<<win[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
	}
}