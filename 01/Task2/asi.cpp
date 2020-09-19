/**
    asi.cpp
    Purpose: To compute Adaptive Simpson Integration (ASI) (Task 2)
    Associated files: asi.hpp
    @author Aron Andersson aronande@kth.se, Harsha HN harshahn@kth.se
    @version 1.0 22 sept 2019
*/
#include <iostream>
#include <math.h>  
#include "asi.hpp"
using namespace std;

//Returns fully computed ASI
double ASI(FunctionPointer f, double a, double b, double tol) {
	double I1, I2; 
	//I1 and I2 are compute, error > tol further partition in [a,b] is made
	I1 = I(f, a, b);
	double c = 0.5 * (a + b); //Mid point
	I2 = I(f, a, c) + I(f, c, b);
	double errest = fabs(I1 - I2);
	if (errest < 15 * tol) return I2;
	else return ASI(f, a, c, tol / 2) + ASI(f, c, b, tol / 2);
}

//Returns computed integral from a to b using Simpson rule
double I(FunctionPointer f, double aa, double bb) {
	double c = (aa + bb) * 0.5;
	//Implemented as per the definition of Simpson
	return ((bb - aa) / 6) * (f(aa) + 4 * f(c) + f(bb));
}