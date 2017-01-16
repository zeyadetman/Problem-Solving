//written by Sharaf
#include <iostream>
#include <iomanip>
using namespace std;
#define p(d) cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(6)<<d<<endl;
int main()
{
	double s,e,sum;
	int N,n;
	cin>>N;
	n = N;
	while(N--)
	{
		cin>>s>>e;
		sum = (e+1)/(s+1);
		sum *= s;
		cout<<"Case "<<n-N<<": ";
		p(sum);
	}
}
