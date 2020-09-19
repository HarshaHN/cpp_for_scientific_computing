
#ifndef STRAIGHTYLINEBOUNDARY_HPP
#define STRAIGHTYLINEBOUNDARY_HPP

//Left and right boundary curves task2. 
class StraightYLineBoundary : public Curvebase {
public:
	StraightYLineBoundary(double ymin, double ymax, double xConstant) : xConstant_(xConstant) {
		pmin = ymin;
		pmax = ymax;
		length = pmax-pmin;
	}
	~StraightYLineBoundary() {}

private:
	double xConstant_;

	double xp(double p);
	double yp(double p);
	double dxp(double p);
	double dyp(double p);

};

#endif