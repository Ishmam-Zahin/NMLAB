#include<bits/stdc++.h>

using namespace std;

class EulerMethod{
	double x0;
	double xn;
	double y0;
	double h;
	double n;

	double functionValue(double x, double y){
		return (x+y+(x*y));
	}
public:
	EulerMethod(double xx0, double yy0, double nn, double xxn){
		x0 = xx0;
		y0 = yy0;
		xn = xxn;
		n = nn;
		h = (xn-x0)/n;
		// h=0.025;
	}

	double run(){
		double yNow = y0, xNow=x0;
		while(xNow < xn){
			// cout<<xNow<<'\n';
			yNow = yNow + h*functionValue(xNow, yNow);
			xNow = xNow+h;
		}

		return yNow;

	}
};

int main(){
	EulerMethod obj(0, 1, 100, .1);
	cout<<obj.run();
}