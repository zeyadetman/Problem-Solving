//Written by Hesham
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int N, M;
string all[10000];

bool ok(string s){
	int j = 0;
	for(int i = 0; i < N; ++i){
		for(int sz = 0; sz <= min((int)all[i].size(), j); ++sz){
			string prfx = all[i].substr(0, sz);
			string sfx = s.substr(j - sz, sz);
			if(prfx != sfx)
				continue;
			string sub1 = all[i].substr(sz, all[i].size() - sz);
			string sub2 = s.substr(j, sub1.size());
			if(sub1 == sub2){
				j += sub1.size();
				break;
			}
		}
		if(j == M)
			return true;
	}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ++ti){
		cin >> N >> M;
		for(int i = 0; i < N; ++i)
			cin >> all[i];

		string curr(M, 'a');
		int res = 0;
		for(int m = 0; m < (1 << M); ++m){
			for(int b = 0; b < M; ++b)
				curr[b] = ((m & (1 << b)) ? 'a' : 'b');
	
			res += ok(curr);
		}
		cout << "Case " << ti << ": " << res << endl;

	}
}
