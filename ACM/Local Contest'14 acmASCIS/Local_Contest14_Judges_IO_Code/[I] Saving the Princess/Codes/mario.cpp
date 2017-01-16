//Written by Taha
// esta3anna 3al sha2a belAllah ..
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<iomanip>
#include<cstring>
#include<bitset>
#include<fstream>
#include<cmath>
#include<cassert>
#include <stdio.h>
#include<ctype.h>
using namespace std;
#define rep(i,n,m) for(int i = (int)(n), _m = (int)(m); i < _m; ++ i)
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
struct state{
	int i, j, mask, steps;
	state(){}
	state(int i, int j, int mask = 0, int steps = 0): i(i), j(j), mask(mask), steps(steps) {
	}
	bool operator ==(state &other) const{
		return other.i == i && other.j == j;
	}
};
bool visited[50][50][1 << 10];
bool get(state s) {
	return visited[s.i][s.j][s.mask];
}
void Set(state s) {
	visited[s.i][s.j][s.mask] = true;
}
int n, m;
char grid[50][50];
bool valid(state s) {
	return s.i >= 0 && s.j >= 0 && s.i < n && s.j < m && grid[s.i][s.j] != '#';
}
int BFS(state start, state destination) {
	queue<state> q;
	memset(visited, false, sizeof visited);
	q.push(start);
	Set(start);
	while(!q.empty()) {
		state curr = q.front();
		q.pop();
		if(curr == destination)
			return curr.steps;
		rep(k, 0, 4) {
			state nxt(curr.i + di[k], curr.j + dj[k], curr.mask, curr.steps + 1);
			if(valid(nxt)) {
				if(islower(grid[nxt.i][nxt.j]))
					nxt.mask ^= 1 << (grid[nxt.i][nxt.j] - 'a');
				else if(isupper(grid[nxt.i][nxt.j]) && (nxt.mask & (1 << (grid[nxt.i][nxt.j] - 'A'))) == 0)
					continue;
				if(!get(nxt)) {
					Set(nxt);
					q.push(nxt);
				}
			}
		}
	}
	return -1;
}
int main() {
	state start, destination;
	int cases;
	cin >> cases;
	rep(C, 1, cases + 1) {
		cin >> n >> m;
		rep(i, 0, n)
			rep(j, 0, m) {
				cin >> grid[i][j];
				if(grid[i][j] == '*')
					start = state(i, j);
				else if(grid[i][j] == '$')
					destination = state(i, j);
		}
		cout << "Case " << C << ": " << BFS(start, destination) << endl;
	}
}