#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Local
using namespace std;
typedef long long ll;
const ll L = 1e6 + 7;
const ll mod = 1e9 + 7;

int pi[L], num[L];
void sol()
{

    // memset(pi,0,sizeof(pi));
    // memset(num,0,sizeof(num));
    string s;
    cin >> s;
    int len = s.length();
    num[0] = 0, num[1] = 1;
    pi[0] = -1, pi[1] = 0;
    int j = 0;
    for (int i = 1; i < len; i++)
    {
        while (j >= 0 && s[j] != s[i])
            j = pi[j];
        // if ( s[i] == s[j] ) j++;
        // pi[i] = j;
        pi[i + 1] = ++j;
        // num[i] = (j==0) ? 0:num[j-1] +1;
        num[i + 1] = num[j] + 1;
    }
    // for(int i=1;i<len;i++){
    //     cout<<"pi["<<i<<"]=="<<pi[i]<<"\n";
    // }
    // for(int i=1;i<len;i++){
    //     cout<<"num["<<i<<"]=="<<num[i]<<"\n";
    // }
    ll ans = 1;
    // for(int i=1;i<len;i++){
    //     int j  = pi[i];
    //     int k = i;
    //     while ( (j<< 1)>i+1 ){
    //         cout<<"i,j"<<j<<" "<<i<<endl;
    //         k=j-1;
    //         j=pi[j-1];
    //     }
    //     ll tmp = num[k] +1;
    //     cout<<"k"<<k<<endl;
    //     ans *= tmp;
    //     ans %= mod;
    // }
    // for (int i = 1; i < len; i++)
    // {
    //     cout << "pi[" << i << "]==" << pi[i] << "\n";
    // }
    j = 0;
    for (int i = 1; i < (int)s.length(); i++)
    {
        // cout << "1------->\n";
        while (j >= 0 && s[i] != s[j])
        {
            // cout << " 1   i,j" << i << " " << j << endl;
            j = pi[j];
        }
        j++;
        // cout << "2=====>\n";
        while ((j << 1) > (i + 1))
        {
            // cout << "i,j" << i << " " << j << endl;
            j = pi[j];
            // cout << j << endl;
        }

        ans *= (unsigned long long)num[j] + 1;
        ans %= mod;
        // cout << "end ==== \n\n";
    }
    cout << ans << endl;
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