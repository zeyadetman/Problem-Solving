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
#define rep(i,n,m) for(int i = (int)(n), _m = (int)(m); i < _m; ++ i)

int main() {
	string str, str2 = "ACMASCIS";
	map<char, int> freq;
	int cases;
	cin >> cases;
	rep(C, 1, cases + 1) {
		freq.clear();
		cin >> str;
		rep(i, 0, 8) {
			freq[str[i]] --;
			freq[str2[i]] ++;
		}
		int res = 0;
		for(map<char, int>::iterator it = freq.begin(); it != freq.end(); ++ it)
			res += it->second * (it->second > 0);
		cout << "Case " << C << ": " << res << endl;
	}
}