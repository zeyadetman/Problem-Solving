//Writtrn by Hesham
#include<iostream>
#include<queue>
#include<stdio.h>
#include<cstring>
using namespace std;
#define MAX_R 50
#define MAX_C 50
#define TYPES 10
bool vis[MAX_R][MAX_C][1 << TYPES];
int dist[MAX_R][MAX_C][1 << TYPES];
char grid[MAX_R][MAX_C];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
#define setb(mask, bit) (mask|((1LL)<<bit))
#define resetb(mask, bit) (mask&(~((1LL)<<bit)))
#define is0(mask, bit)((mask&((1LL)<<bit))==0)
#define is1(mask, bit)((mask&((1LL)<<bit))!=0)
struct State {
	int y, x, m;
	State() {}
	State(int yy, int xx, int mm) :
			y(yy), x(xx), m(mm) {
	}
};
int r, c;
int bfs(int sy, int sx) {

	memset(vis, false, sizeof vis);
	vis[sy][sx][0] = true;
	dist[sy][sx][0] = 0;

	queue<State> q;
	q.push(State(sy, sx, 0));

	while (!q.empty()) {
		State curr = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];
			int nm = curr.m;
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
				continue;
			if (grid[ny][nx] == '#')
				continue;
			if (grid[ny][nx] >= 'A' && grid[ny][nx] < 'A' + TYPES) {
				int b = grid[ny][nx] - 'A';
				if (is0(curr.m, b))
					continue;
			}
			if (grid[ny][nx] >= 'a' && grid[ny][nx] < 'a' + TYPES) {
				int b = grid[ny][nx] - 'a';
				if (is1(curr.m, b))
					nm = resetb(nm, b);
				else
					nm = setb(nm, b);
			}
			if(vis[ny][nx][nm])
				continue;
			vis[ny][nx][nm] = true;
			dist[ny][nx][nm] = dist[curr.y][curr.x][curr.m] + 1;
			if (grid[ny][nx] == '$')
				return dist[ny][nx][nm];
			q.push(State(ny, nx, nm));
		}
	}
	return -1;
}

int main() {
	//freopen("marioIn.txt", "r", stdin);
	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ++ti) {
		cin >> r >> c;
		int sy, sx;
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j) {
				cin >> grid[i][j];
				if (grid[i][j] == '*') {
					sy = i;
					sx = j;
				}
			}
		}
		cout << "Case " << ti << ": " << bfs(sy, sx) << endl;
	}
}

