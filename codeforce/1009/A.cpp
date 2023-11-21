#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define ll long long
#define fir first
#define sec second
#define pii pair<int, int>
#define LOCAL
using namespace std;

const int maxn = 200005;
const int inf = 0x3f3f3f3f;

signed main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int x = 0;
        cin >> x;
        if (x >= 7 && (x - 7) % 3 == 0)
        {
            int tmp = (x - 7) / 3;
            cout << "YES" << endl;
            cout << 1 << " " << 4 << " " << 2 + tmp * 3 << "\n";
            continue;
        }
        if (x >= 8 && (x - 8) % 3 == 0)
        {
            int tmp = (x - 8) / 3;
            cout << "YES" << endl;
            cout << 2 << " " << 5 << " " << 1 + tmp * 3 << "\n";
            continue;
        }
        if (x >= 12 && (x - 12) % 3 == 0)
        {
            int tmp = (x - 12) / 3;
            cout << "YES" << endl;
            cout << 1 << " " << 4 << " " << 7 + tmp * 3 << "\n";
            continue;
        }
        if (x >= 15 && (x - 15) % 3 == 0)
        {
            int tmp = (x - 15) / 3;
            cout << "YES" << endl;
            cout << 2 << " " << 5 << " " << 8 + tmp * 3 << "\n";
            continue;
        }
        cout << "NO" << endl;
    }
}