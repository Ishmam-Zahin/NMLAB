#include<bits/stdc++.h>

using namespace std;

class NewtonDividedDifference{
	int n;
	double value;
	vector<double> x;
	vector<double> y;
public:
	NewtonDividedDifference(int nn, vector<double> &xx, vector<double> &yy, double vvalue){
		n = nn;
		x = xx;
		y = yy;
		value = vvalue;
	}

	double run(){
		for(int i=1; i<n; i++){
			double past = y[i-1];
			for(int j=i; j<n; j++){
				double tmp=y[j];
				y[j]=((y[j]-past)/(x[j]-x[j-i]));
				past=tmp;
				// cout<<y[j]<<' ';
			}
			// cout<<'\n';
		}

		double result=0;
		double past=1;
		for(int i=0; i<n; i++){
			if(i==0){
				result+=y[i];
			}
			else{
				past=past*(value-x[i-1]);
				result+=(past*y[i]);
			}
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

	NewtonDividedDifference obj(n, x, y, value);
	cout<<obj.run();

	// for(int i=0; i<n; i++){
	// 	cout<<y[i]<<'\n';
	// }
}