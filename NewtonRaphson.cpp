#include<bits/stdc++.h>

using namespace std;

class NewtonRaphson{
	double x0;
	const int n = 100;
public:
	double funtionalValue(double x){
		return (x*x*x - x*x + 2);
	}
	double dFunctionalValue(double x){
		return (3*x*x -2*x);
	}
	void guessX0(){
		srand(time(0));
		do{
			x0 = -9+rand()%10;
			if(dFunctionalValue(x0)!=0) break;
		}while(true);
	}
	double run(){
		guessX0();
		// cout<<x0<<'\n';
		int step = 0, x1;
		while(true){
			x1 = x0 - ((funtionalValue(x0))/dFunctionalValue(x0));
			// cout<<x1<<'\n';
			if(funtionalValue(x1) == 0) break;
			step++;
			if(step>n) break;
			x0=x1;
		}

		return x1;
	}
};

int main(){
	NewtonRaphson obj;
	cout<<obj.run();
}