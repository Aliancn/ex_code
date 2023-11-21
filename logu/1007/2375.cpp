#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Local
using namespace std;
typedef long long ll;
const ll L = 1e6+7;
const ll mod = 1e9+7;

int pi[L], num[L];
void sol()
{
    string s ;
    cin>>s;
    int len = s.length();
    num[0] =0 ;
    pi[0] = 0;
    for(int i=1;i<len;i++){
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i] ) j= pi[j-1];
        if ( s[i] == s[j] ) j++;
        pi[i] = j;
        num[i] = (j==0) ? 0:num[j-1] +1;
    }
    ll ans =1;
    int j=0;
    for(int i=1;i<len;i++){
        while (j>0 && s[i] != s[j])
        {
            j = pi[j-1];
        }
        if (s[i] == s[j] ) j++;
        while ( (j<< 1)>i+1 ){
            j = pi[j-1];
        }
        // j =0 k=0, j=1 k=1, j>1 k=num[j-1]+1 
        int k = (j==0)? 0: num[j-1]+1;
        ll tmp = k +1;
        ans *= tmp;
        ans %= mod;
    }
    cout<<ans <<endl;
}

int main()
{
#ifdef Local
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}