#include "Curvebase.hpp"
#include "BottomFunction.hpp"
#include <cmath>

double BottomFunction::xp(double p) {
	return p;
}

double BottomFunction::yp(double p) {

	if (p < -3.0) {
		return 0.5 / (1.0 + exp(-3.0 * (p + 6.0)));
	}
	else {
		return 0.5 / (1.0 + exp(3.0 * p));
	}
}

double BottomFunction::dxp(double p) {
	return 1.0;
}

double BottomFunction::dyp(double p) {

	if (p < -3.0) {
		return 1.5 * exp(3.0 * (p + 6)) / (1.0 + 2.0 * exp(3.0 * (p + 6.0)) + exp(6.0 * (p + 6.0)));
	}
	else {
		return -1.5 * exp(3.0 * p) / (1.0 + 2.0 * exp(3.0 * p) + exp(6.0 * p));
	}
}