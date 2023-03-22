#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;


int cha[30];
string str;
signed main() {
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    // cout<<(int )'a';
    // return 0;
	int T;
	cin>>T;
	while(T--) {
        memset(cha,0,sizeof(cha));
        int n;
		cin>>n;
        cin>>str;
      
  
        int temp;
        int last;
        int flag=0;
        for(int i=0;i<n;i++){

            temp = (int )str[i]-96;
            // cout<<"temp: "<<temp<<endl;
            if(i>0){
                if(!cha[temp]){
                    cha[temp]=3-last;
                    
                }
                else {
                    if(cha[temp]==last){
                        cout<<"NO"<<endl;
                        flag=1;
                        break;
                    }
                }
                last = cha[temp];
            }
            else{
                last=1;
                cha[temp]=1;
            }
        }
        if(!flag){
            cout<<"YES"<<endl;
        }
	}
}