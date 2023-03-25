#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

int num[5];
signed main() {

	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);


	int T;
	cin>>T;
	while(T--) {
		char a[5];
		for(int i=1;i<=4;i++){
			cin>>a[i];
		}
		sort(a+1,a+5);
		int temp=1;
		num[temp]=1;
		for(int i=2;i<=4;i++){
			if(a[i]>a[i-1]) temp++;
			num[temp]++;
		}

		switch (temp)
		{
		case 1:
			cout<<-1<<endl;
			break;
		case 2:
			if(num[1]==2){
				cout<<4<<endl;
			}
			else{
				cout<<6<<endl;
			}
			break;
		case 3:
			cout<<4<<endl;
			break;
		case 4:
			cout<<4<<endl;
			break;
		default:
			break;
		}
	}
}