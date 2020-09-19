/**
    main.cpp
    Purpose: Adaptive Simpson Integration (ASI) (Task 2)
    Associated files: asi.hpp asi.cpp
    @author Aron Andersson aronande@kth.se, Harsha HN harshahn@kth.se
    @version 1.0 22 sept 2019
*/

#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include "asi.hpp"
using namespace std;
#define clrscr() cout << "\033[2J\033[1;1H";

// func to be integrated
double our_Function(double x) {
	return 1 + sin(exp(3*x));
}

int main() {
	clrscr();
	cout << "\n" << "---Task 2: Adaptive Simpson Integration (ASI)---" << "\n";
	
	double I; double tol[3] = {1e-2, 1e-3, 1e-4}; //tol
	for (int i = 0; i < 3; i++) {
		I = ASI(&our_Function, -1.0, 1.0, tol[i]);
		cout << "Appx. of integral of func 1 + sin(exp(3*x)), with tol. "
		<< tol[i] << ": " << setprecision(10) << I << endl;
	}
	return 0;
}
