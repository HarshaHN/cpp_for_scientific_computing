#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double myexp(double x, double tol = 1e-10);

int main() {
	double answer; double x = 2.0;

	answer = myexp(x);
	cout << "\n" << "Our exponential function gives for x=" << x << ": " << setprecision(20) << answer << endl;
	cout << "exp from standard library gives for x=" << x << ": " << exp(x) << endl;

}

double myexp(double x, double tol) {
	double result = 0, expLib; int i = 1; double a;

	expLib = exp(x); //from standard library cmath
	result = result + pow(x, 0) / 1; // for when factorial is 0!
	while (abs(expLib - result) > tol){
		a = pow(x, i);
		for (int j = 1; j <= i; j++) {
			a *=(double)1/j; //factorial
		}
		result = result + a;
		i = i + 1;
	}
	return result;
}