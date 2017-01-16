//written by Hesham
#include<iostream>

#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	string acmASCIS = "ACMASCIS";
	string A;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> A;

		int cost = 0;
		for(char c = 'A'; c <= 'Z'; ++c){
			int acmCount = count(acmASCIS.begin(), acmASCIS.end(), c);
			int aCount = count(A.begin(), A.end(), c);
			cost += max(0, acmCount - aCount);
		}
		cout << "Case " << i << ": " << cost << endl;
	}
}
