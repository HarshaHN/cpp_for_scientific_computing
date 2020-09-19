#ifndef BOTTOMFUNCTION_HPP
#define BOTTOMFUNCTION_HPP
#include <cmath>

//Left and right boundary curves
class BottomFunction : public Curvebase {
public:
	BottomFunction(double xmin, double xmax) {
		pmin = xmin;
		pmax = xmax;
		length = integrate(pmax);
	}
	~BottomFunction() {}

private:
	double xp(double p);
	double yp(double p);
	double dxp(double p);
	double dyp(double p);

};

#endif
