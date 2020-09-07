#include "Curvebase.hpp"
#include "StraightXLineBoundary.hpp"

double StraightXLineBoundary::xp(double p) {
	return p;
}

double StraightXLineBoundary::yp(double p) {
	return yConstant_;
}

double StraightXLineBoundary::dxp(double p) {
	return 1;
}

double StraightXLineBoundary::dyp(double p) {
	return 0;
}