#ifndef STRAIGHTXLINEBOUNDARY_HPP
#define STRAIGHTXLINEBOUNDARY_HPP

//Left and right boundary curves
class StraightXLineBoundary : public Curvebase {
public:
	StraightXLineBoundary(double xmin, double xmax, double yConstant) : yConstant_(yConstant) {
		pmin = xmin;
		pmax = xmax;
		length = xmax - xmin;
	}
	~StraightXLineBoundary() {}

private:
	double yConstant_;
	double xp(double p);
	double yp(double p);
	double dxp(double p);
	double dyp(double p);

};

#endif