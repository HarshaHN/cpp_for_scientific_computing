#ifndef DOMAIN_HPP
#define DOMAIN_HPP
#include "Curvebase.hpp"
#include <array>

class Domain {
public:
	Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4);
	Domain(const Domain&);
	Domain& operator=(Domain&);
	~Domain();
	void generate_grid(int m, int n);
	void writeToFile();
	// more members

private:
	Curvebase* sides[4]; //**sides?
	double *x_, *y_;
	int m_, n_;
	bool check_consistency();
	inline double phi1(double s); //lecture 5, page 13
	inline double phi2(double s);
	double phix(double eps, double eta);
	double phiy(double eps, double eta);
	// more members

};
#endif
