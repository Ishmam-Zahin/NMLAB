#include<bits/stdc++.h>

using namespace std;

class GaussJordan{
	vector<vector<double>> matrix;
	int n, m;
public:
	GaussJordan(int nn, int mm, vector<vector<double>> &mmatrix){
		n = nn;
		m = mm;
		matrix = mmatrix;
	}
	void transformMatrix(){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i!=j){
					double fact=(matrix[j][i]/matrix[i][i]);
					for(int k=0; k<m; k++){
						// cout<<j<<' '<<k<<'\n';
						matrix[j][k]=(matrix[j][k]-(fact*matrix[i][k]));
					}
				}
			}
		}
	}
	double run(){
		// cout<<m<<'\n';
		transformMatrix();
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) cout<<matrix[i][j]<<' ';
				cout<<'\n';
		}
	}
	
};

int main(){
	int n, m;
	cin>>n>>m;
	// double matrix[n][m];
	vector<vector<double>> matrix(n, vector<double>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>matrix[i][j];
		}
	}

	GaussJordan obj(n, m, matrix);
	obj.run();
}