//written by Taha 
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
#define	rrep(i,n,m) for(int i = (int)(n), _m = (int)(m); i >= _m; -- i)
string arr[10001];
int n;
bool can(string str) {
	int j = 0;
	rep(i, 0, n) {
		rrep(start, min(j, (int)str.size() - (int)arr[i].size()), max(0, j - (int)arr[i].size())) {
			string b = str.substr(start, arr[i].size());
			if(arr[i] == b) {
				j = start + arr[i].size();
				break;
			}
		}
		if(j == str.size())
			break;
	}
	return j == str.size();
}
int main() {
	int cases, m;
	cin >> cases;
	rep(C, 1, cases + 1) {
		cin >> n >> m;
		rep(i, 0, n)
			cin >> arr[i];
		int res = 0;
		rep(mask, 0, 1 << m) {
			string str;
			rep(j, 0, m)
				if(mask & (1 << j))
					str += "a";
				else
					str += "b";
			res += can(str);
		}
		cout << "Case " << C << ": " << res << endl;
	}
}