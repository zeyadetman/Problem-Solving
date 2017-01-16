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
#define MAX 100001
#define EPSILON 1e-9
struct BIT {
	vector<long long> v;
	BIT(int s) {
		resize(s);
	}
	void clear() {
		v.clear();
	}
	BIT() {
	}
	void resize(int s) {
		s = 1 << (int) ceil(log(1.0 * s) / log(2.) + EPSILON);
		v.resize(s);
	}
	int get(int i) {
		i++;
		int r = 0;
		while (i) {
			r += v[i - 1];
			i -= i & -i;
		}
		return r;
	}
	int get(int a, int b) {
		return get(b) - (a == 0? 0: get(a - 1));
	}
	void add(int i, int val) {
		i++;
		while (i <= (int) v.size()) {
			v[i - 1] += val;
			i += i & -i;
		}
	}
}BITs[11];
int sqrts[] = {INT_MAX, INT_MAX, 46340, 1290, 215, 73, 35, 21, 14, 10, 8};
vector<int> perfect[11];
void init() {
	for(int k = 2; k <= 10; ++ k)
		for(int j = 1; j <= sqrts[k]; ++ j)
			perfect[k].push_back(powl(j, k));
}
void clearBITs() {
	for(int i = 2; i <= 10; ++ i) {
		BITs[i].clear();
		BITs[i].resize(MAX);
	}
}
int main() {
//	freopen("input.txt","r",stdin);
	init();
	int cases, n, m, id, v, k, i, j;
	cin >> cases;
	for(int C = 1; C <= cases; ++ C) {
		cin >> n >> m;
		clearBITs();
		for(i = 0; i < n; ++ i) {
			cin >> v;
			for(k = 2; k <= 10; ++ k)
				if(binary_search(perfect[k].begin(), perfect[k].end(), v))
					BITs[k].add(i, 1);
		}
		cout << "Case #" << C << ":" << endl;
		for(int q = 0; q < m; ++ q) {
			cin >> id;
			if(id == 0) {
				cin >> i >> v;
				for(k = 2; k <= 10; ++ k) {
					if(BITs[k].get(i, i))
						BITs[k].add(i, -1);
					if(binary_search(perfect[k].begin(), perfect[k].end(), v))
						BITs[k].add(i, 1);
				}
			}
			else {
				cin >> i >> j >> k;
				if(k == 1) // special case.
					cout << "Yes" << endl;
				else if(BITs[k].get(i, j) == (j - i + 1))
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		}
	}
}
