//Written by tasniem
#include <iostream>
#include <math.h>

using namespace std;

int intersection(float x0, float y0, float r0, float x1, float y1, float r1, float *xi, float *yi, float *xi_prime, float *yi_prime)
{
	float a, dx, dy, d, h, rx, ry;
	float x2, y2;

	dx = x1 - x0;
	dy = y1 - y0;
	d = hypot(dx,dy);

	if (d > (r0 + r1))
		return 0;
	if (d < fabs(r0 - r1))
		return 0;

	a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0 * d) ;
	x2 = x0 + (dx * a/d);
	y2 = y0 + (dy * a/d);

	h = sqrt((r0*r0) - (a*a));
	rx = -dy * (h/d);
	ry = dx * (h/d);

	*xi = x2 + rx;
	*xi_prime = x2 - rx;
	*yi = y2 + ry;
	*yi_prime = y2 - ry;

	return 1;
}


int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	float x0, y0, r0, x1, y1, r1, x3, y3, x3_prime, y3_prime;
	int cases;
	cin >> cases;
	for(int C = 1; C <= cases; ++ C)
	{
		cin >> x0 >> y0 >> r0 >> x1 >> y1 >> r1;
		cout << "Case " << C << ": ";
		if(intersection(x0, y0, r0, x1, y1, r1, &x3, &y3, &x3_prime, &y3_prime))
		{
			double dx = x3_prime - x3;
			double dy = y3_prime - y3;
			double d = hypot(dx, dy);
			cout << d << endl;
		}
		else
			cout << "No intersection." << endl;
	}
}


