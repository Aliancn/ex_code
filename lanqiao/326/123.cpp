#include <iostream>
#include <math.h>
#define pii pair<int,int> 
#define ll long long
using namespace std;
// 等差数列求和
ll sum(ll a1, ll an, ll n) {
    return n * (a1 + an) / 2;
}
// 求和
ll getGap(ll l, ll r) {
    ll ret = 0;
    ll n = r - l;
    ll m = n - 1;
    ll a1 = sum(1, l, l);
    ll an = a1 + m * l;
    // 单纯计算A的总值
    ret += sum(a1, an, n);
    
    // 需要计算剩余值，使用平方和公式与等差数列求和
    if (n >= 2) {
        ret += sum(1, m, m) * (m + 1) - m * (m + 1) * (2 * m + 1) / 6;
    }
    return ret;
}
// 获取组号与具体位置
pii get(ll pos) {
    double tmp = sqrt(pos * 2) - 0.5;
    ll group = (ll)tmp + 1;
    ll number = pos - (group * (group - 1)) / 2;
    return { group,number };
}

int main()
{
    ll n;
    cin.tie();
    cin >> n;
    while (n--) {
        ll l, r;
        cin >> l >> r;
        pii left = get(l);
        pii right = get(r);
        
        cout << getGap(left.first, right.first) + sum(1,right.second,right.second) - sum(1,left.second-1,left.second - 1) << endl;
    }
    return 0;
}
