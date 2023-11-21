#include <iostream>
#include <vector>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
const int maxn = 3010;
// int mix[maxn];
int change[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int tt;
    cin >> tt;

    while (tt--)
    {
        cin >> n;
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            string mix;
            cin>>mix;
            for (int j = 1; j <= n; j++)
            {
                if (i == 1)
                {
                    if (mix[j-1]=='1'){
                        ans ++;
                        cout<<"ij:"<<i<<" "<<j<<"\n";
                        change[i][j] = 1;
                    }else{
                        change[i][j] =0;
                    }
                }
                else
                {
                    change[i][j] = 0;
                    for (int k = max(1, j - 1); k <= min(n, j + 1); k++)
                    {
                        change[i][j] ^= change[i - 1][k];
                    }
                    if (change[i][j] ^ (mix[j]-'0')){
                        change[i][j]^= 1;
                        ans ++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}