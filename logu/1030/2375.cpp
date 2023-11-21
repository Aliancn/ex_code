#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Local
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int L = 1e6 + 7;
int num[L], pi[L];
void sol()
{
    string s;
    cin >> s;
    int length = s.length();
    num[0] = 0, pi[0] = 0;
    for (int i = 1; i < length; i++)
    {
        int j = pi[i - 1]; // j 是长度，是下一个位置
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        num[i] = (j==0) ? 0:num[j-1] +1;
        // cout<<"pi "<<pi[i]<<" num "<<num[j-1]<<endl;
    }
    ll ans = 1;
    int j = 0;
    for (int i = 1; i < length; i++)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        while ( (j<<1) > i+1){
            j = pi[j-1];
        }
        int k = (j==0)? 0: num[j-1]+1;
        ll tmp = k+1;
        // cout<<"j+1 "<<j+1<<" k+1 "<<k+1<<endl;

        ans *= tmp;
        ans %= mod;
    }
    cout<<ans<<endl;
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