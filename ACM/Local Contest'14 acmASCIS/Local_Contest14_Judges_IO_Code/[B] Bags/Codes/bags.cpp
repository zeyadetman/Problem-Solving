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
long double dp[1001][101];
int m;
long double rec(int passed, int rem) {
	if(rem == 0)
		return passed;
	if(rem == m - passed)
		return m;
	long double &res = dp[passed][rem];
	if(res == res)
		return res;
	long double p = (long double)rem / (m - passed);
	return res = p * rec(passed + 1, rem - 1) + (1.0 - p) * rec(passed + 1, rem);
}
int main() {
	int cases, n;
	cin >> cases;
	while(cases --) {
		cin >> n >> m;
		memset(dp, -1, sizeof dp);
		cout << fixed << setprecision(6) << rec(0, n) << endl;
	}
}