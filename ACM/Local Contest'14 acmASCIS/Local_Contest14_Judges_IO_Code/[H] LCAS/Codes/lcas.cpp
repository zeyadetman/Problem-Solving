//Written by Taha
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

int a[1001], b[1001];
int dp[1001][1001][2], n, m;

int LCAS(int i, int j, bool odd) {
	if(i == n || j == m)
		return 0;
	int &res = dp[i][j][odd];
	if(res != -1)
		return res;
	if(a[i] == b[j] && a[i] % 2 == odd)
		return res = LCAS(i + 1, j + 1, !odd) + 1;
	else
		return res = max(LCAS(i + 1, j, odd), LCAS(i, j + 1, odd));
}
int building_table() {
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < m; ++ j)
			for(int mod = 0; mod < 2; ++ mod) {
				dp[i][j][mod] = 0;
				if(i)
					dp[i][j][mod] = max(dp[i][j][mod], dp[i - 1][j][mod]);
				if(j)
					dp[i][j][mod] = max(dp[i][j][mod], dp[i][j - 1][mod]);
				if(i && j && a[i] == b[j] && a[i] % 2 == mod)
					dp[i][j][mod] = max(dp[i][j][mod], dp[i - 1][j - 1][1 - mod] + 1);
				else if(a[i] == b[j] && a[i] % 2 == mod)
					dp[i][j][mod] = max(dp[i][j][mod], 1);
			}
	return max(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cases;
	cin >> cases;
	for(int C = 1; C <= cases; ++ C) {
		cin >> n >> m;
		for(int i = 0; i < n; ++ i)
			cin >> a[i];
		for(int i = 0; i < m; ++ i)
			cin >> b[i];
		//memset(dp, -1, sizeof dp);
		//cout << "Case " << C << ": " << max(LCAS(0, 0, 0), LCAS(0, 0, 1)) << endl;
		cout << "Case " << C << ": " << building_table() << endl;
	}
}
