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

#define MOD 1000000007

int nCr[101][101], factorial[101];

void initialize() {
	for(int i = 0; i <= 100; ++ i)
		nCr[i][0] = nCr[i][i] = 1;
	factorial[0] = 1;
	for(int i = 1; i <= 100; ++ i) {
		factorial[i] = (factorial[i - 1] * (long long)i) % MOD;
		for(int j = 1; j < i; ++ j)
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
	}
}

int dp[101][101];
int n, a[101];

int count(int indx, int remFrames) {
	if(indx == n)
		return remFrames == 0;
	int &res = dp[indx][remFrames];
	if(res != -1)
		return res;
	res = 0;
	for(int assigned = 1; assigned <= min(a[indx], remFrames); ++ assigned) {
		int curr = count(indx + 1, remFrames - assigned);
		curr = (curr * (long long) nCr[remFrames][assigned]) % MOD;
		curr = (curr * (long long) nCr[a[indx] - 1][a[indx] - assigned]) % MOD;
		curr = (curr * (long long) factorial[a[indx]]) % MOD;
		res = (res + curr) % MOD;
	}
	return res;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	initialize();
	int cases, m, total;
	cin >> cases;
	for(int T = 1; T <= cases; ++ T) {
		cin >> n >> m;
		total = 0;
		for(int i = 0; i < n; ++ i) {
			cin >> a[i];
			total += a[i];
		}
		if(total < m || n > m)
			cout << "Case " << T << ": " << "Invalid" << endl;
		else {
			memset(dp, -1, sizeof dp);
			cout << "Case " << T << ": " << count(0, m) << endl;
//			assert(count(0, m) != 0);
		}
	}
}
