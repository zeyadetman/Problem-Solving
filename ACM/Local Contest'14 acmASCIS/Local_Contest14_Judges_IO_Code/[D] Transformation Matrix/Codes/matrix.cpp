//Written by Hesham
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define oo 2000000000
struct Node {
	int to, rIndex, flow;
	int cost;
	Node(int t, int r, int f, int c) :
			to(t), rIndex(r), flow(f), cost(c) {
	}
	Node() {
	}
};
vector<vector<Node> > adjList;
vector<bool> visited;
vector<pair<int, int> > pred;
void addEdge(int from, int to, int flow, int cost) {
	Node n1(to, adjList[to].size(), flow, cost);
	Node n2(from, adjList[from].size(), 0, -cost);
	adjList[from].push_back(n1);
	adjList[to].push_back(n2);
}

const int MAX_VERTICES = 1203;
int cost[MAX_VERTICES];
bool dijkstra(int src, int sink) {
	for (int i = 0; i < adjList.size(); ++i)
		cost[i] = oo;
	cost[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (sink == u)
			return true;
		for (int i = 0; i < adjList[u].size(); ++i) {
			int v = adjList[u][i].to;
			if (cost[v] > cost[u] + adjList[u][i].cost && adjList[u][i].flow) {
				cost[v] = cost[u] + adjList[u][i].cost;
				pred[v] = make_pair(u, i);
				pq.push(make_pair(-cost[v], v));
			}
		}
	}
	return false;
}
int augment(int src, int sink) {
	if (!dijkstra(src, sink))
		return 0;
	int minCap = oo;
	int to = sink, f;
	while (to != src) {
		int from = pred[to].first;
		int toIndx = pred[to].second;
		if (adjList[from][toIndx].flow < minCap)
			minCap = adjList[from][toIndx].flow;
		to = from;
	}
	to = sink;
	while (to != src) {
		int from = pred[to].first;
		int toIndx = pred[to].second;
		adjList[from][toIndx].flow -= minCap;

		int rev = adjList[from][toIndx].rIndex;
		adjList[to][rev].flow += minCap;
		to = from;
	}
	return minCap;
}
pair<int, int> mcmf(int src, int sink) {
	int maxFlow = 0;
	int minCost = 0;
	int currFlow;
	while (currFlow = augment(src, sink)) {
		maxFlow += currFlow;
		minCost += cost[sink];
		visited = vector<bool>(adjList.size(), false);
	}
	return make_pair(maxFlow, minCost);
}
void initAugment(int n) {
	visited.clear();
	visited.resize(n, false);
	pred.clear();
	pred.resize(n);
}
void init(int n) {
	adjList.clear();
	adjList.resize(n);
	initAugment(n);
}

int n, m;
#define SRC 0
#define SINK (1 + n * m * 3)
#define id(i, j, k) (i * m + j + k * (n * m) + 1)
int A[20][20];
int B[20][20];
int C[20][20];
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, -1, 0, 1, 1, -1, 1, -1 };

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ++ti) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		cin >> A[i][j];
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		cin >> B[i][j];
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		cin >> C[i][j];
		init(n * m * 3 + 2);
		int onesA = 0;
		int onesB = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				onesA += A[i][j];
				onesB += B[i][j];
				if (A[i][j])
				addEdge(SRC, id(i, j, 1), 1, 0);
				if (B[i][j])
				addEdge(id(i, j, 1), SINK, 1, 0);
				int insrt, remove;
				if (!C[i][j])
				insrt = remove = 0;
				else if (A[i][j] == B[i][j])
				insrt = remove = C[i][j] / 2;
				else if (A[i][j]) {
					insrt = (C[i][j] - 1) / 2;
					remove = (C[i][j] - 1) / 2 + 1;
				} else {
					insrt = (C[i][j] - 1) / 2 + 1;
					remove = (C[i][j] - 1) / 2;
				}
				addEdge(id(i, j, 0), id(i, j, 1), insrt, 0);
				addEdge(id(i, j, 1), id(i, j, 2), remove, 0);
				for (int d = 0; d < 8; ++d) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny < 0 || ny == n || nx < 0 || nx == m)
					continue;
					addEdge(id(i, j, 2), id(ny, nx, 0), oo, 1);
				}
			}
		}
		cout << "Case " << ti << ": ";
		if (onesA != onesB)
		cout << -1 << endl;
		else
		{
			pair<int, int> p = mcmf(SRC, SINK);
			if (p.first < onesA)
			cout << -1 << endl;
			else
			cout << p.second << endl;
		}

	}

}
