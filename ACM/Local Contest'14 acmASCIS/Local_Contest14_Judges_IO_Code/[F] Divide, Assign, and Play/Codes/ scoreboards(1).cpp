//Written by Hesham
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include <stdio.h>
using namespace std;
#define MAX_FRAMES 100
#define MAX_SCORE 100
#define GET_MAX(i, j) (i > j ? i : j)
int C[MAX_FRAMES + MAX_SCORE][GET_MAX(MAX_FRAMES, MAX_SCORE) + 1];
int F[MAX_SCORE + 1];
int frames, groups;
#define LL long long
#define MOD ((LL)1000000007)
int calcChoose(int n, int c) {
	if (n == 0)
		return !c;
	if (C[n][c] != -1)
		return C[n][c];
	C[n][c] = calcChoose(n - 1, c);
	if (c)
		C[n][c] += calcChoose(n - 1, c - 1);
	C[n][c] %= MOD;
	return C[n][c];
}
#define MAX_GROUPS 100
int scores[MAX_GROUPS];
int dp[MAX_GROUPS][MAX_FRAMES + 1];

int count(int i, int rem) {
	if (i == groups)
		return !rem;
	if (!rem)
		return 0;
	if (dp[i][rem] != -1)
		return dp[i][rem];
	int res = 0;
	for (int x = 1; x <= min(rem, scores[i]); ++x) {
		LL curr = ((LL)calcChoose(rem, x) * (LL)F[scores[i]]) % MOD;
		curr *= (LL)calcChoose(scores[i] - 1, scores[i] - x);
		curr %= MOD;
		curr *= (LL)count(i + 1, rem - x);
		curr %= MOD;
		res += curr;
		res %= MOD;
	}
	return dp[i][rem] = res;
}
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	memset(C, -1, sizeof C);
	F[0] = 1;
	for (int i = 1; i <= 100; ++i) {
		F[i] = ((LL)F[i - 1] * (LL)i) % MOD;
	}
	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ++ti) {
		cin >> groups >> frames;
		int sum = 0;
		for (int i = 0; i < groups; ++i) {
			cin >> scores[i];
			sum += scores[i];
		}
		if (sum < frames || groups > frames)
			cout << "Case " << ti << ": Invalid" << endl;
		else {
			memset(dp, -1, sizeof dp);
			cout << "Case " << ti << ": " << count(0, frames) << endl;
		}
	}
}
