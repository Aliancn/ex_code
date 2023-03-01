#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
#define LOCAL

struct OIL { //汽油 
	double cost, x; //价格 和 油量 
	OIL(double c, double n) : cost(c), x(n) {}
};
double d1, c, d2, D[10], P[10], ans, nc; //nc (<= c)是当前的油量
int n;
deque<OIL> p; //STL双端队列 实现 

int main() {
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
	scanf("%lf%lf%lf%lf%d", &d1, &c, &d2, &P[0], &n);
	for(int i=1; i<=n; i++) {
		scanf("%lf%lf", &D[i], &P[i]);
		if(D[i] - D[i-1] > c * d2) { //无解很好判断:装满油也跑不完这一段 
			printf("No Solution\n");
			return 0;
		}
	}
	D[n+1] = d1; //把终点设为第n+1个加油站 距离为d1 
	p.push_back(OIL(P[0], nc = c)); //直接加满 
	ans += P[0] * c;
	for(int i=1; i<=n+1; i++) { //从第i-1个加油站到第i个加油站 
		double nd = (D[i] - D[i-1]) / d2;  //跑这一段需要多少升汽油
		while(!p.empty() && nd > 0) {  //不断循环直到跑完这这一段 
			OIL front = p.front(); p.pop_front(); //每次找最便宜的油跑 
			if(front.x > nd)  { //这种油够跑 
				nc -= nd;
				p.push_front(OIL(front.cost, front.x - nd));
				break;
			}
			nc -= front.x; nd -= front.x;
		}
		if(i == n+1) { //到达终点:退回所有油 
			while(!p.empty()) {
				ans -= p.front().cost * p.front().x;
				p.pop_front();
			}
			break;
		} 
		while(!p.empty() && p.back().cost > P[i]) { //把贵的油退了 换成当前加油站的便宜油 
			ans -= p.back().cost * p.back().x;
			nc -= p.back().x;
			p.pop_back();
		}
		ans += (c - nc) * P[i];
		p.push_back(OIL(P[i], c - nc)); //每次加满(多了后面再退)
		nc = c; 
	}
	printf("%.2lf\n", ans);
	return 0;
}