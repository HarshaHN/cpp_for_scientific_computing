#ifndef CURVEBASE_HPP
#define CURVEBASE_HPP

//lecture 6, page 28
class Curvebase {

public:
	//functionspointer to handle the computation of integral
	typedef double (Curvebase::*FunctionPointer)(double); 

	//constructor
	Curvebase() {} //Default constructor, just allocating memory for 4
	virtual ~Curvebase() {}
	double x(double s); //arc length parametrization
	double y(double s); //arc length parametrization
	//more?

protected:
	double pmin; // minimal value for p
	double pmax; // maximal value for p
	bool rev; // orientation of the curve
	double length;
	//more?

	virtual double xp(double p) = 0;
	virtual double yp(double p) = 0;
	virtual double dxp(double p) = 0;
	virtual double dyp(double p) = 0;

	//func(p) = 0
	double f(double p, double s);
	double df(double p);
	double newtonMethod(double p_guess, double s, double tol);

	//Following four functions: Project 1, task 2 evaluation of an integral.
	double integrate(double p); //arc length integral
	double ASI(FunctionPointer f, double a, double b, double tol);
	double I(FunctionPointer f, double aa, double bb);
	//more?

};


#endif






