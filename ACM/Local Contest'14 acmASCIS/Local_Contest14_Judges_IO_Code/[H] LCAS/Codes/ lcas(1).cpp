//written by Hesham
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<cstring>
#include<bitset>
#include<fstream>
#include<cmath>
#include<cassert>
#include <stdio.h>
#include<ctype.h>
using namespace std;
int dp[1000][1000][2];
int N, M;
int s1[1000];
int s2[1000];
int rec(int i, int j, bool odd)
{
	if(i == N || j == M)
		return 0;
	if(dp[i][j][odd] != -1)
		return dp[i][j][odd];
	if(s1[i] == s2[j] && s1[i] % 2 != odd)
		return dp[i][j][odd] = rec(i + 1, j + 1, !odd) + 1;

	return dp[i][j][odd] = max(rec(i + 1, j, odd), rec(i, j + 1, odd));

}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ++ti)
	{
		cin >> N >> M;
		for(int i = 0; i < N; ++i)
			cin >> s1[i];
		for(int i = 0; i < M; ++i)
			cin >> s2[i];
		memset(dp, -1, sizeof dp);
		cout << "Case " << ti << ": " << max(rec(0, 0, 0), rec(0, 0, 1)) << endl;
	}
}
