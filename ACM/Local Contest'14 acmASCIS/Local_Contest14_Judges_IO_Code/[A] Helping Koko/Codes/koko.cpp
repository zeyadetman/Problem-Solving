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

int main() {
	freopen("input.txt", "r", stdin);
	int cases;
	long long A, B, C;
	cin >> cases;
	for(int T = 1; T <= cases; ++ T) {
		cin >> A >> B >> C;
		if(A + B == C)
			cout << "Case " << T << ": " << "True" << endl;
		else
			cout << "Case " << T << ": " << "False" << endl;
	}
}
