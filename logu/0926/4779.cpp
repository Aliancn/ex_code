#include<iostream>
#include<cstring>
using namespace std;


const int maxn =5e5 +100;
int n;
int k;
string str;

struct hextree{
	int col[maxn<<2],mark[maxn<<2];
	hextree(){
		memset(mark,-1,sizeof(mark));
	}

	void pushup(int now){
		// 判断左右子区间是否同色
		if(col[now<<1]==col[(now<<1)|1]){
			col[now] = col[now<<1];
		}
		else{
			col[now]= -1 ;
		}
	}
	void pushdown(int now ){
		// 下移tag
		if (mark[now] != -1){
			col[now<<1]=col[(now<<1)|1]=mark[now];
			mark[now<<1] = mark[(now<<1)|1] = mark[now];
			mark[now] = -1;
		}
	}
	void build (int l,int r ,int now){
		if ( l == r){
			col[now] = str[l-1]-'A' +1;
			return ;
		}
		int mid = (l+r)>>1;
		build(l, mid, now<<1);
		build(mid+1, r, (now<<1)|1);
		pushup(now); // 注意这里
	}

	void fix (int x,int y,int z,int l,int r,int now){
		if (x>r || y< l){
			return ;
		}
		if (x<=l && r<=y){
			col[now] = mark[now]=z;
			return ;
		}
		pushdown(now);

		int mid = (l+r)>>1;
		fix(x,y,z,l,mid,now<<1);
		fix(x,y,z,mid+1,r,(now<<1)|1);
		pushup(now);
	}

	int draw (int x, int y, int l,int r,int now ){
		if (x>r || l>y){
			return 0;
		}
		if (x<=l && r<=y) return col[now];
		pushdown(now);
		int mid = (l+r)>>1;
		int nxt_l,nxt_r;
		nxt_l = draw( x,  y,  l, mid, now <<1);
		nxt_r = draw( x,y,mid+1,r,(now<<1)|1);
		if (nxt_l==0) return nxt_r;
		if (nxt_r==0) return nxt_l;
		if(nxt_r == -1 || nxt_l == -1 ) return -1;
		if (nxt_l == nxt_r ) return nxt_l;
		return -1; 
 	}
} tree;


int main(){
	cin>>n>>str>>k;
	tree.build(1, n, 1);
	// cout<<n<<str<<k<<endl;
	// cout<<tree.draw(3, 3, 1, n, 1)<<endl;
	while(k--){
		int x ,y;
		char sign ,op;
		cin>>sign ;
		if (sign == 'A'){
			cin>>x>>y>>op;
			tree.fix(x, y, op-'A'+1,1,n,1);
		}
		else if (sign == 'B') {
			cin>>x>>y;
			int l,r;
			l = tree.draw(x-1, x-1, 1, n, 1);
			r = tree.draw(y+1, y+1, 1, n, 1);
			// cout<<"x ,y , l, r is " <<x<<y<<l<<r<<endl;
			if (tree.draw(x, y, 1, n, 1) != -1 && (l!=r || !l || !r)){
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
	}

	return 0;
}