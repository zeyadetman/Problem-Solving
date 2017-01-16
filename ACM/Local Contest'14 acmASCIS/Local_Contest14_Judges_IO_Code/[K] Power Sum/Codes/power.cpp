//Written by Sharaf
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define MAX_N 55

ull C[MAX_N][MAX_N];

struct Matrix {
	ll mat[MAX_N][MAX_N];
	Matrix(){
		memset(mat, 0, sizeof(mat));
	}
};

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans; int i, j, k;
	for (i = 0; i < MAX_N; i++)
		for (j = 0; j < MAX_N; j++)
			for (ans.mat[i][j] = k = 0; k < MAX_N; k++) {
				ans.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
				ans.mat[i][j] %= MOD;
			}
			return ans;
}

Matrix matPow(Matrix base, int p) {
	Matrix ans; int i, j;
	for (i = 0; i < MAX_N; i++)
		for (j = 0; j < MAX_N; j++)
			ans.mat[i][j] = (i == j);
	while (p) {
		if (p & 1)
			ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}
	return ans;
}

Matrix prepareInitial(int K) {
	Matrix m;
	for(int i = 1; i <= K+1; i ++)
		for(int j = i; j <= K+1; j ++)
			m.mat[i][j] = C[K-i+1][j-i];
	for(int i = 1; i <= K+1; i ++)
		m.mat[0][i] = m.mat[1][i], m.mat[i][0] = 0;
	m.mat[0][0] = m.mat[K+1][K+1] = 1;
	return m;
}

void compC()
{
	C[0][0] = 1;
	for(int i = 1; i < MAX_N; i ++)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j ++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
}

Matrix getVector(int K)
{
	Matrix v;
	for(int i = 0; i < K+2; i ++)
		v.mat[i][0] = 1;
	return v;
}
int main() {
//	freopen("in.in","r",stdin);
//	freopen("out.txt","w",stdout);
	compC();
	Matrix m, v;
	int t, n, k, cc = 1;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		m = prepareInitial(k);
		m = matPow(m, n-1);
		v = getVector(k);
		v = matMul(m,v);
		cout<<"Case "<<cc++<<": "<<v.mat[0][0]<<endl;
	}
}