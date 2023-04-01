#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 15e5 + 5;
ll s[N];
ll sum[N];
void init() {
    for (int i = 1; i < N; i++) {
        s[i] = s[i - 1] + i;
        sum[i] = sum[i - 1] + s[i];
    }
}
ll find(ll x) {
    ll l = 1, r = N - 5;
    ll mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (s[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
ll t, l, r;
int main() {
    init();
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &l, &r);
        int fl = find(l);
        int fr = find(r);
        ll ans = sum[fr] - sum[fl - 1] - s[l - 1 - s[fl - 1]] - s[fr] + s[r - s[fr - 1]];
        printf("%lld\n", ans);
    }
    return 0;
}