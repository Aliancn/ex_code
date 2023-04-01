#include<bits/stdc++.h>
#define Inf 0x3F3F3F3F
#define Loc freopen("baka.in", "r", stdin)
typedef long long LL;
using namespace std;
 
int main() {
    LL A, B, N; cin >> A >> B >> N;
    A %= B;
    while (N > 10) {
        A *= 1E10; A %= B; N -= 10;
    }
    for (int pos = 0; pos < N + 2; pos++) {
        A *= 10; 
        if (pos >= N - 1) cout << A / B; /* 是后三位的时候输出 */
        A %= B;
    }
}