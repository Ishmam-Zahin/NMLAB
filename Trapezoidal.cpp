#include<bits/stdc++.h>

using namespace std;

class Trapezoidal{
};

int main(){
	EulerMethod obj(0, 1, 100, .1);
	cout<<obj.run();
}