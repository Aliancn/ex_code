#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define ll long long
#define fir first
#define sec second
#define pii pair<int, int>
using namespace std;
#define LOCAL
const int maxn = 200005;
const int inf = 0x3f3f3f3f;

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point() {}
};
double getLength(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

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
        Point yuan(0, 0);
        Point a, b, p;
        cin >> p.x >> p.y;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;

        double len_OP = getLength(yuan, p);
        double len_AO = getLength(yuan, a);
        double len_BO = getLength(yuan, b);
        double len_AB = getLength(a, b);
        double len_AP = getLength(p, a);
        double len_BP = getLength(p, b);

        double ans = 5e3;
        if (len_AB / 2 > len_AO && len_AB / 2 > len_AP || len_AB / 2 > len_BO && len_AB / 2 > len_BP)
        {
            if (len_AB / 2 > len_AO && len_AB / 2 > len_AP)
            {
                double tmp = max(len_AO, len_AP);
                ans = min(ans, tmp);
            }
            if (len_AB / 2 > len_BO && len_AB / 2 > len_BP)
            {
                double tmp = max(len_BO, len_BP);
                ans = min(ans, tmp);
            }
        }
        else
        {
            if (len_AB / 2 > len_AO && len_AB / 2 > len_BP)
            {
                ans = len_AB / 2;
            }
            else if (len_AB / 2 > len_BO && len_AB / 2 > len_AP)
            {
                ans = len_AB / 2;
            }
            else
            {
                // aop
                ans = min(ans, max(getLength(a, yuan), getLength(a, p)));
                // bop
                ans = min(ans, max(getLength(b, yuan), getLength(b, p)));
                // ao bp
                ans = min(ans, max(getLength(a, yuan), getLength(b, p)));
                // ap bo
                ans = min(ans, max(getLength(a, p), getLength(b, yuan)));
            }
        }
        printf("%.10lf\n", ans);
    }
}