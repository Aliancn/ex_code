#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;

//求组合数
LL C(LL a, int b)
{
	LL res = 1;
	for (int i = a, j = 1; j <= b; i--, j++)
	{
		res = res * i / j;
		if (res > n)	return res;
	}
	return res;
}

bool check(int k)
{
	//下限是2*k，上限最差是n，当k=1时，C(n,1)=n
	LL l = 2 * k, r = max(n, l);
	while (l < r)
	{
		LL mid = l + r >> 1;
		if (C(mid, k) >= n)	r = mid;
		else l = mid + 1;
	}
	if (C(r, k) != n)	return false;
	//下标为r的位置前面有r+1行（等差公式得r*(r+1)/2）
	cout << (LL)r * (r + 1) / 2 + k + 1 << endl;
	return true;
}

int main()
{
	cin >> n;
	//从最大的斜行往前枚举
	for (int k = 16;; k--)
		if (check(k))
			break;
	return 0;
}
