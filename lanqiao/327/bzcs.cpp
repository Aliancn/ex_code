/*
数学问题，是属于求解A1x1+A2X2+…+AiXi=C不定方程的类型，有数学家已经证明了Ax+By=C，在A，B不互质时有无限个使方程无解的C，在A，B互质时使方程无解的C有限，且使方程无解的C的最大值小于A*B-A-B。通过上述结论，可以得出:

*1.只要A1…Ai中存在两个下标为x，y的数互质，则使得方程无解的C有限，且C<=A[x]A[y]-A[x]-A[y]。

*/
//
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> Ai;
int f[10000];

int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int data;
		cin >> data;
		Ai.push_back(data);
	}
	int max;
	bool flag=false;
	for (int i = 0; i < Ai.size()&&!flag; i++){//判断解是否有限
		for (int j = i+1; j < Ai.size(); j++)
		{
			if (gcd(Ai[i], Ai[j]) == 1) {
				max = Ai[i] * Ai[j] - Ai[i] - Ai[j];
				flag = true;
				break;
			}
		}
	}
	if (!flag) {
		cout << "INF\n";
		return 0;
	}
	f[0] = true;
	for (int i = 0; i <= max; i++) {//处理背包问题
		for (int j = 0; j < Ai.size()&&f[i]; j++) {
			if(i + Ai[j]<=max)
				f[i + Ai[j]] = true;
		}
	}
	int num = 0;
	for (int i = 0; i <= max; i++){//统计解的个数
		if (!f[i])
			num++;
	}
	cout << num;
	return 0;
}			
