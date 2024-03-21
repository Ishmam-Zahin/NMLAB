#include<bits/stdc++.h>

using namespace std;

class FalsePosition{
	double x1, x2;
	const double e=0.0001;
public:
	double functionValue(double x){
		return x*x*x - x*x + 2;
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
			if(functionValue(x0)*functionValue(x1)<0){
				x2=x0;
			}
			else{
				x1=x0;
			}
			xm = ((x1*functionValue(x2))-(x2*functionValue(x1)))/(functionValue(x2) - functionValue(x1));
		}while(fabs((xm-x0)/x0)>e);

		return x0;
	}
};

int main(){
	FalsePosition obj;
	cout<<obj.run();
}