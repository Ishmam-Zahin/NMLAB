#include<bits/stdc++.h>

using namespace std;

class NewtonForward{
	int n;
	double value;
	double u;
	double h;
	double a;
	vector<double> x;
	vector<double> y;
public:
	NewtonForward(int nn, vector<double> &xx, vector<double> &yy, double vvalue){
		n = nn;
		x = xx;
		y = yy;
		value = vvalue;
		a = x[0];
		h = x[1] - x[0];
		u = (value - a) / h;
	}

	double run(){
		// cout<<u<<'\n';
		for(int i=1; i<n; i++){
			double past = y[i-1];
			for(int j=i; j<n; j++){
				double tmp=y[j];
				y[j]=((y[j]-past));
				past=tmp;
				// cout<<y[j]<<' ';
			}
			// cout<<'\n';
		}

		double result=0;
		double fact_u=1, fact_hor = 1;
		for(int i=0; i<n; i++){
			if(i==0){
				result+=y[i];
			}
			else{
				fact_u*=(u-i+1);
				fact_hor*=i;
				result+=(((fact_u)/(fact_hor))*y[i]);
			}
			// cout<<result<<'\n';
		}

		return result;
	}
};

int main(){
	int n;
	cin>>n;
	vector<double> x(n), y(n);
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	double value;
	cin>>value;

	NewtonForward obj(n, x, y, value);
	cout<<obj.run();

	// for(int i=0; i<n; i++){
	// 	cout<<y[i]<<'\n';
	// }
}