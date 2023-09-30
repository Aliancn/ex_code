#include <iostream>
#define Local
using namespace std;
typedef long long ll;
const int maxn = 5e5+100;
int x[maxn],y[maxn];
int a[maxn],b[maxn];
char op[maxn];
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=m;i++){
        cin>>op[i];
        if (op[i] == 'm'){
            cin>>a[i]>>b[i];
        }
    }
    int dx=0 ,dy=0;
    int fx =1,fy=1;
    for(int i=m;i>=1;i--){
        if (op[i] == 'm'){
            dx += fx?a[i]:(-a[i]);
            dy += fy?b[i]:(-b[i]);
        }
        else if (op[i] == 'x'){
            fx ^= 1;
        }
        else if (op[i] == 'y'){
            fy ^= 1;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<(fx?1:-1)*(x[i] + dx) <<" "<<(fy?1:-1)*(y[i] + dy)<<"\n";
    }
}

int main()
{
#ifdef Local
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}