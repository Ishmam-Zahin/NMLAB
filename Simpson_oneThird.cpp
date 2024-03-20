#include<bits/stdc++.h>

using namespace std;

class SimpsonOneThird{
	double xn;
	double x0;
	double n;
	double h;

	double functionValue(double x){
		return log(x);
	}
public:
	SimpsonOneThird(double xx0, double xxn, double nn){
		x0 = xx0;
		xn = xxn;
		n = nn;
		h = (xxn - xx0) / n;
	}

	double run(){
		double result = 0;
		vector<double> x(n+1), fx(n+1);
		for(int i=0; i<=n; i++){
			if(i==0){
				x[i] = x0;
				fx[i] = functionValue(x[i]);
			}
			else{
				x[i] = x[i-1] + h;
				fx[i] = functionValue(x[i]);
			}
		}

		for(int i=0; i<=n; i++){
			if(i==0 || i==n){
				result += fx[i];
			}
			else if(i%2 != 0){
				result += (4*fx[i]);
			}
			else{
				result += (2*fx[i]);
			}
		}

		return (result*h)/3;
	}
};

int main(){
	SimpsonOneThird obj(4, 5.2, 6);
	cout<<obj.run();
}