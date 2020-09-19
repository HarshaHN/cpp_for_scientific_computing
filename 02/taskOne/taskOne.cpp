/**
    taskOne.cpp
    Purpose: evaluation of the exponential for real numbers (Task 1)
    @author Harsha HN harshahn@kth.se, Aron Andersson aronande@kth.se
    @version 1.0 22 Oct 2019
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define clrscr() cout << "\033[2J\033[1;1H"; //To clear the console

double myexp(double x, double tol = 1e-10);

int main() {
	//clrscr();
	double ans, x, tol, err= 1e-20;
	double listX[] = {-1, 1, 5, 20, 50};
	double listTol[] = {0.01, 0.001, 1e-8, 1e-10};

	for (int i = 4; i < 5; i++) { 
		x = listX[i]; cout << "\n"<< "Number = " << x << endl;
		for (int j = 0; j < 4; j++) {
			tol= listTol[j];
			cout << " tolerance = " << tol << endl;
			ans= myexp(x, tol); err= abs(ans-exp(x));
			cout << " myexp= " << setprecision(20) << ans;
			cout << " exp(x)= " << setprecision(20) << exp(x);
			cout << " err= " << err << endl;
		}
	}
	return 0;
}

double myexp(double x, double tol) {
	double ans = 1; 
	int N = 1; double val = 1;

	//Find N: number of terms to be computed
	while(abs(val) > tol){
		N++; val = 1;
		for(int j = N; j > 0; j--){
			val = x / j * val;
			}
	}
	cout << "  Terms= "<< N;
	//Compute by horner's scheme
	for(int i = N; i > 0; i--){
		ans = 1 + (x/i)*ans;
	}

	return ans;
}