//Written by Sharaf
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std ;
#define all(v) v.begin(),v.end()
#define sz size()
#define pb(x) push_back(x)
#define mp make_pair
typedef long long ll;
//r:(a,b)  s:(c,d)
double f(double a, double b, double c, double d, double r, double s)
{
	double e,f,p,k,ans,x1,y1,x2,y2;
	e = abs(c - a);
	f = abs(d - b);
	p = hypot(e,f);
	if(p>r+s)
		return -1;
	k = (p*p + r*r - s*s)/(2*p);
	x1 = a + e*k/p + (f/p)*sqrt(r*r - k*k);
	x2 = a + e*k/p - (f/p)*sqrt(r*r - k*k);
	y1 = b + f*k/p - (e/p)*sqrt(r*r - k*k);
	y2 = b + f*k/p + (e/p)*sqrt(r*r - k*k);
	return hypot(x1-x2,y1-y2);
}
int main()
{
	int t;
	double a,b,c,d,r,s,ans;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>r>>c>>d>>s;
		cout<<"Case "<<i<<": ";
		ans = f(a,b,c,d,r,s);
		if(ans==-1)
			cout<<"No intersection."<<endl;
		else
			cout<<ans<<endl;
	}
}
