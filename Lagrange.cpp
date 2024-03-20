#include<bits/stdc++.h>

using namespace std;

class Lagrange{
	int n;
	vector<double> x;
	vector<double> y;
	double value;
public:
	Lagrange(int nn, vector<double> &xx, vector<double> &yy, double vvalue){
		n = nn;
		x = xx;
		y = yy;
		value = vvalue;
	}
	double run(){
		double result=0;
		for(int i=0; i<n; i++){
			double tmp=y[i];
			for(int j=0; j<n; j++){
				if(j!=i){
					// cout<<((value-x[j])/(x[i]-x[j]))<<'\n';
					tmp*=((value-x[j])/(x[i]-x[j]));
				}
			}
			result+=tmp;
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
	Lagrange obj(n, x, y, value);
	cout<<obj.run();
}