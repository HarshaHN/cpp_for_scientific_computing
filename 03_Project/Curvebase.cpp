#include <iostream>
#include <math.h>  
#include "Curvebase.hpp"
using namespace std;

//f function
//lecture 6, page 10. 
double Curvebase::f(double p, double s) {
	return integrate(p) - s * length;
}

//df function
double Curvebase::df(double p) {
	return sqrt(dxp(p) * dxp(p) + dyp(p) * dyp(p));
}

//Integral
double Curvebase::integrate(double p) {
	double integral;
	double tol = 1e-8;
	integral = ASI(&Curvebase::df, pmin, p, tol);

	return integral;
}

double Curvebase::ASI(FunctionPointer f, double a, double b, double tol) {
	double I1, I2;
	//I1 and I2 are compute, error > tol further partition in [a,b] is made
	I1 = I(f, a, b);
	double c = 0.5 * (a + b); //Mid point
	I2 = I(f, a, c) + I(f, c, b);
	double errest = fabs(I1 - I2);
	if (errest < 15 * tol) return I2;
	else return ASI(f, a, c, tol / 2) + ASI(f, c, b, tol / 2);
}

double Curvebase::I(FunctionPointer f, double aa, double bb) {
	double c = (aa + bb) * 0.5;
	//Implemented as per the definition of ASI
	return ((bb - aa) / 6) * ((*this.*f)(aa) + 4 * (*this.*f)(c) + (*this.*f)(bb)); //*this is dereferencing. The same with *f.
}

//Newton method
//Lecture 6 (: Inheritance, chapter : Transformation to Arc Length) and lecture 2 (secant method).
double Curvebase::newtonMethod(double p_guess, double s, double tol) {
	double error = tol + 1, p;
	int it = 0, itMax = 100;

	while (error > tol && it < itMax) {
		if (it == itMax) {
			cerr << "No convergence! Exiting..." << endl;
			exit(0);
		}
		else {
			p = p_guess - f(p_guess, s) / df(p_guess);
			error = fabs(p - p_guess);
			p_guess = p;
			it++;
		}
	}

	return p;

}

//Arc length parametrization. Lecture 6: Inheritance, chapter: Transformation to Arc Length 
//Coordinates
double Curvebase::x(double s) {
	double p_guess, p;
	double tol = 1e-6;

	if (s >= 0 && s <= 1) {
		p_guess = s * length + pmin; // s = (p_guess-pMin)/length, s is the normalized arc length. u_hat = u/lengt_of_u
		p = newtonMethod(p_guess, s, tol);
	}
	else {
		cerr << "input value s is a normalized parameter, should be between 0 and 1" << endl;
		exit(0);
	}

	return xp(p);
}


//Arc length parametrization. Lecture 6: Inheritance, chapter: Transformation to Arc Length 
//Coordinates
double Curvebase::y(double s) {
	double p_guess, p;
	double tol = 1e-6;

	if (s >= 0 && s <= 1) {
		p_guess = s * length + pmin; // s = (p_guess-pMin)/length, s is the normalized arc length. u_hat = u/lengt_of_u
		p = newtonMethod(p_guess, s, tol);
	}else {
		cerr << "input value s is a normalized parameter, should be between 0 and 1" << endl;
		exit(0);
	}
	return yp(p);
}
