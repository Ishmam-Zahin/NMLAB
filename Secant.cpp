#include<bits/stdc++.h>

using namespace std;

class Secant{
	double x1, x2;
	const double e=0.0001;
public:
	double functionValue(double x){
		return x*x*x + x - 1;
	}
	void guessX1X2(){
		srand(time(0));
		do{
			x1=rand()%10 - 9;
			x2=rand()%10;
			// cout<<functionValue(x1)<<' '<<functionValue(x2)<<'\n';

		}while(functionValue(x1)*functionValue(x2)>0);
		// cout<<x1<<' '<<x2<<'\n';
	}
	double run(){
		guessX1X2();
		double x0, xm;
		do{
			x0=((x1*functionValue(x2))-(x2*functionValue(x1)))/(functionValue(x2) - functionValue(x1));
			if(functionValue(x0)==0) break;
			x1 = x2;
			x2 = x0;

			xm = ((x1*functionValue(x2))-(x2*functionValue(x1)))/(functionValue(x2) - functionValue(x1));
		}while(fabs(xm-x0)>e);

		return x0;
	}
};

int main(){
	Secant obj;
	cout<<obj.run();
}