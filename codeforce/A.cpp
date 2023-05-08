#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

int n,d;
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
       n=0;
       d=0;

       cin>>n>>d;
       string str;
       int i=0;
        cin>>str;
        for( i=0;i<str.length();i++){
            if(int(str[i]-'0')<d) break;
            // if(int(str[i]-'0')==d){
            //     for(;i<str.length();i++){
            //         if(int(str[i]-'0')<d) break;
            //     }
            //     break;
            // }
        }
        
        for(int j=0;j<=n;j++){
            if(j<i){
                cout<<str[j];
            }
            else if(j==i){
                cout<<d;
            }
            else if(j>i){
                cout<<str[j-1];
            }
        }
        cout<<endl;
	}
    return 0;
}