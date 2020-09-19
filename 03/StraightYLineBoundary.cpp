#include "Curvebase.hpp"
#include "StraightYlineBoundary.hpp"

double StraightYLineBoundary::xp(double p) {
	return xConstant_;
}

double StraightYLineBoundary::yp(double p) {
	return p;
}

double StraightYLineBoundary::dxp(double p) {
	return 0;
}

double StraightYLineBoundary::dyp(double p) {
	return 1;
}

