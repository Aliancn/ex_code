/*
1.tarjan+并查 的主要思想在于对于一个公共节点，先探测完了左边
  在探测右边，必然会找到左边的值，此时返回的正是最近的公共节点
2.需要存边和查询操作
3.注意边的奇偶存法
*/
#include <algorithm>
#include <iostream>
using namespace std;

class Edge {
 public:
  int toVertex, fromVertex;
  int next;
  int LCA;
  Edge() : toVertex(-1), fromVertex(-1), next(-1), LCA(-1){};
  Edge(int u, int v, int n) : fromVertex(u), toVertex(v), next(n), LCA(-1){};
};

const int MAX = 100;
int head[MAX], queryHead[MAX];
Edge edge[MAX], queryEdge[MAX];//边和查询关系
int parent[MAX], visited[MAX];
int vertexCount, edgeCount, queryCount;

void init() {
  for (int i = 0; i <= vertexCount; i++) {
    parent[i] = i;
  }
}

int find(int x) {
    return parent[x]==x?x:find(x);
}

void tarjan(int u) {
  parent[u] = u;
  visited[u] = 1;

    for (int i = head[u]; i != -1; i = edge[i].next) {
    Edge& e = edge[i];
    if (!visited[e.toVertex]) {
      tarjan(e.toVertex);//搜索
      parent[e.toVertex] = u;//更新
    }
  }
    //当我们开始处理这一点的查询关系时，公共节点的左侧以及节点到
    //这里之前的点都已经被处理完成了
    //而且此时点已经并入了公共祖先
    for (int i = queryHead[u]; i != -1; i = queryEdge[i].next) {
    Edge& e = queryEdge[i];
    if (visited[e.toVertex]) {
      queryEdge[i ^ 1].LCA = e.LCA = find(e.toVertex); 
      //这里的1^i表示奇数则取偶，偶数则取奇，作用是翻转第一位
    }
  }
}

int main()
{
  memset(head, 0xff, sizeof(head));
  memset(queryHead, 0xff, sizeof(queryHead));

  cin >> vertexCount >> edgeCount >> queryCount;
  int count = 0;
  for (int i = 0; i < edgeCount; i++)
  {
    int start = 0, end = 0;
    cin >> start >> end;
    // 都采用奇偶存边的方法，，一条边存两遍
    // 可已通过异或的方法快速的得到另一条边
    edge[count] = Edge(start, end, head[start]);
    head[start] = count;
    count++;

    edge[count] = Edge(end, start, head[end]);
    head[end] = count;
    count++;
  }

  count = 0;
  for (int i = 0; i < queryCount; i++)
  {
    int start = 0, end = 0;
    cin >> start >> end;

    queryEdge[count] = Edge(start, end, queryHead[start]);
    queryHead[start] = count;
    count++;

    queryEdge[count] = Edge(end, start, queryHead[end]);
    queryHead[end] = count;
    count++;
  }

  init();
  tarjan(1);

  for (int i = 0; i < queryCount; i++)
  {
    Edge &e = queryEdge[i * 2];
    cout << "(" << e.fromVertex << "," << e.toVertex << ") " << e.LCA << endl;
  }

  return 0;
}
