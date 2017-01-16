//Written by Sharaf
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std ;
typedef long long ll;
string q[2] = {"False","True"};
int main()
{
	ll t,a,b,c;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		cout<<"Case "<<i<<": "<<q[a+b==c]<<endl;
	}
}
