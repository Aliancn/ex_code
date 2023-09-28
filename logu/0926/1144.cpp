// 9 - 26 最短路计数

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 1e6+100;
const int mod = 100003;
int n,m;
vector<int>mp[maxn];
int f[maxn] ;
int dep[maxn];
void bfs(){
	queue<int>q;
	q.push(1);
	dep[1] =1 ;
	f[1] =1 ;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i=0;i<mp[tmp].size();i++){
			int nxt = mp[tmp][i];
			if (dep[nxt]==0) {
				dep[nxt] = dep[tmp]+1;
				q.push(nxt);
			}
			if(dep[nxt] == dep[tmp] +1 ){
				f[nxt] = (f[nxt] + f[tmp])%mod; 
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x ,y;
		cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	bfs();
	for(int i=1;i<=n;i++){
		cout<<f[i]<<endl;
	}
	return 0;
}
