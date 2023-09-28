

typedef long long ll;

std::vector<ll> line_mod_equation(ll a, ll b, ll n){
	ll x,y;
	ll d =exgcd(a,n,x,y);
	std::vector<ll> ans;
	ans.clear();
	if(b%d == 0){
		x%=n;
		x+=n;
		x%=n;
		ans.push_back(x%(b/d)%(n/d));
		for(ll i=1 ; i<d ; i++){
			ans.push_back((ans[0]+ i*n/d)%n);
		}
	}
	return ans;
}