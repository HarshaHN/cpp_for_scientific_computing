#include <iostream>
#include <cmath>
#include <cstdio> //task 4
#include "domain.hpp"
#include "Curvebase.hpp"
#include <array>

using namespace std;

//lecture 5
inline double Domain::phi1(double s) {
	return 1 - s;
}

inline double Domain::phi2(double s) {
	return s;
}

//page 14, lecture 4
double Domain::phix(double eps, double eta) {

	/*
	//All the comments are to be sure that its writing the numbers I want. 
	//sides[0] = yLineLeft
	//sides[1] = xLine,
	// sides[2] = yLineRight
	//sides[3] = botten

	
	double epsilon;
	double h1 = 1.0 / 10;

	for (int i = 0; i < 11; i++) {
		epsilon = i * h1;
		cerr << "i = " << i << " gives " << epsilon << endl;
		cerr << "yLineLeft i x-led: " << sides[0]->x(epsilon) << endl;
		cerr << "yLineLeft i y-led: " << sides[0]->y(epsilon) << endl;

	}

	cerr << "\n" << endl;

	for (int i = 0; i < 11; i++) {
		epsilon = i * h1;
		cerr << "xLine i x-led: " << sides[1]->x(epsilon) << endl;
		cerr << "xLine i y-led: " << sides[1]->y(epsilon) << endl;
	}

	cerr << "\n" << endl;

	for (int i = 0; i < 11; i++) {
		epsilon = i * h1;
		cerr << "yLineRight i x-led: " << sides[2]->x(epsilon) << endl;
		cerr << "yLineRight i y-led: " << sides[2]->y(epsilon) << endl;
	}

	cerr << "\n" << endl;

	for (int i = 0; i < 11; i++) {
		epsilon = i * h1;
		cerr << "botten i x-led: " << sides[3]->x(epsilon) << endl;
		cerr << "botten i y-led: " << sides[3]->y(epsilon) << endl;
	}

	exit(1);
	*/

	return phi1(eta) * sides[0]->x(eps) + phi2(eta) * sides[2]->x(eps)
		  +phi1(eps) * sides[3]->x(eta) + phi2(eps) * sides[1]->x(eta) 
		  -phi1(eps) * phi1(eta) * sides[0]->x(0) - phi2(eps) * phi2(eta) * sides[2]->x(1)
		  -phi1(eps) * phi2(eta) * sides[3]->x(1) - phi2(eps) * phi1(eta) * sides[1]->x(0); 
	//exit(0);
}

double Domain::phiy(double eps, double eta) {
	return phi1(eps) * sides[3]->y(eta) + phi2(eps) * sides[1]->y(eta) 
		  +phi1(eta) * sides[0]->y(eps) + phi2(eta) * sides[2]->y(eps) 
		  -phi1(eps) * phi1(eta) * sides[0]->y(0) - phi2(eps) * phi1(eta) * sides[1]->y(0) 
		  -phi1(eps) * phi2(eta) * sides[3]->y(1) -	phi2(eps) * phi2(eta) * sides[2]->y(1);
}      

/*
Task 4
A file called xValues.bin is created and the content of x-list array is stored into it. For simplicity, the x-list contains double elements.
sizeof(buffer) is the length of the array in bytes.
In order to create a file as a binary file, a "wb" character has to be included in the mode string.
"wb"
*/

void Domain::writeToFile(){

	/*
    "w": write: Create an empty file for output operations. If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file. 
	*/

	FILE* fp;
	fp = fopen("xValues.bin", "wb"); //return a nullptr if fopen fails to open the file. "wb" means Create an empty bin file.
	if (fp == nullptr) {
		cerr << "The file is NOT succesfully opened" << endl;
		exit(0);
	}else {

		/*
		for (int i = 0; i < 24; i++) {
			cerr << "\n" << " Write To file, i= " << i << ", x_= " << x_[i] << endl;
		}
		*/
		//cerr << "m_ values and n_ value    " << m_ << ", " << n_ << endl;
		fwrite(x_, sizeof(double), (m_+1) * (n_+1), fp);

		fp = fopen("yValues.bin", "wb");
		fwrite(y_, sizeof(double), (m_+1) * (n_+1), fp);

		fclose(fp);
	}
}

void Domain::generate_grid(int m, int n) {

	if (m <= 0 || n <= 0) {
		cerr << "incorrect values, m and n must be larger than zero" << endl;
		exit(0);
	}
	
	if (m_ > 0) { // There exists already a grid!
		delete[] x_;
		delete[] y_;
	}else{
	m_ = m; n_ = n;
	x_ = new double[(m_+1) * (n_+1)]; //0 index is included.
	y_ = new double[(m_+1) * (n_+1)];
	//Lecture 5. 
	double epsilon, eta;
	double h1 = 1.0 / m_; double h2 = 1.0 / n_; // page 12 lectute 5. 
	for (int i = 0; i < m_ + 1; i++) {
		    epsilon = i * h1;
		for (int j = 0; j < n_ + 1; j++) {
			eta = j * h2;
			x_[i + j * (m_ + 1)] = phix(epsilon, eta); //page 12 and 14 in Lecture 5.	
			y_[i + j * (m_ + 1)] = phiy(epsilon, eta);
			//cerr << i + j * (m_ + 1) << " index in x_ list " << x_[i + j * (m_ + 1)] << endl;
			//cerr << i + j * (m_ + 1) << " index in y_ list " << y_[i + j * (m_ + 1)] << endl;

		}
		
	}
	//exit(0);
	}

}

Domain::Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4) {
	sides[0] = &s1;
	sides[1] = &s2;
	sides[2] = &s3;
	sides[3] = &s4;
	if (check_consistency() == false) {
		sides[0] = sides[1] = sides[2] = sides[3] = nullptr;
	}
	m_ = n_ = 0;
	x_ = y_ = nullptr;
}

Domain::~Domain() {
	if (m_ > 0) {
		delete[] x_;
		delete[] y_;
	}
}

bool Domain::check_consistency() {

	if (fabs(sides[0]->x(1) - sides[1]->x(0)) > 1e-4 ||
		fabs(sides[0]->y(1) - sides[1]->y(0)) > 1e-4) {
		std::cout << "Low-Right corner disconnected" << std::endl;
		return false;

	}

	if (fabs(sides[1]->x(1) - sides[2]->x(1)) > 1e-4 ||
		fabs(sides[1]->y(1) - sides[2]->y(1)) > 1e-4) {
		std::cout << "Top-Right corner disconnected" << std::endl;
		return false;

	}

	if (fabs(sides[2]->x(0) - sides[3]->x(1) > 1e-4) ||
		fabs(sides[2]->y(0) - sides[3]->y(1) > 1e-4)) {
		std::cout << "Top-Left corner disconnected" << std::endl;
		return false;

	}

	if (fabs(sides[3]->x(0) - sides[0]->x(0)) > 1e-4 ||
		fabs(sides[3]->y(0) - sides[0]->y(0)) > 1e-4) {
		std::cout << "Low-Left corner disconnected" << std::endl;
		return false;

	}

	return true;

}