#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 1e6+7;
const int mod = 100003;
const int INF = 1e9+7;
int m,n;

std::vector<int> mp[maxn];
bool book[maxn];
int d[maxn];
int way[maxn];


void spfa (){
	for(int i=1;i<=n;i++){
		d[i] = INF ;
	}
	queue<int> q;
	d[1] =0 ;
	way[1] = 1;
	q.push(1);
	while(!q.empty()){
		int tmp = q.front();q.pop();
		for(int i=0;i<mp[tmp].size();i++){
			int nxt = mp[tmp][i];
			if (d[tmp] + 1 < d[nxt]){
				d[nxt] =d[tmp] +1;
				way[nxt] = way[tmp];
				if (!book[nxt]){
					q.push(nxt);
					book[nxt] =1 ;
				} 
			}
			else if (d[tmp] + 1 == d[nxt]){
				way[nxt] += way[tmp];
				way[nxt] %= mod;
			}
		}
		book[tmp] = 0;
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x ,y;
		cin>>x>>y ;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	spfa();

	for(int i=1;i<=n;i++){
		cout<<way[i]<<endl;
	}

	return 0;
}