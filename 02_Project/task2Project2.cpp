#include <iostream>
#include <math.h> 
#include <vector>
#include "task2Project2.hpp"

/*
From www.eigen.tuxfamily.org we downloaded the latest release,
Eigen 3.3.7, which makes calculation of eigenvalues, in norm(), simple. 
1. Download the package. 
2. If u use GNU. Please write in the terminal, g++ -Wall -I /Users/HP/Downloads/eigen-eigen-323c052e1731/eigen-eigen-323c052e1731/ task2MatrixProject2main.cpp task2Project2.cpp r8lib.cpp r8mat_expm1.cpp -o output 
*/
#include <Eigen/Dense>  
#include <Eigen/Eigenvalues>
using namespace std;


//deconstructor. 
Matrix::~Matrix() {
	for (int i=0; i < this->m_m; ++i) {
		delete[] this->m_mat[i];
	}
	delete[] this->m_mat;
}

double** Matrix::generateMatrix(int m_m){
	double** temp = new double* [m_m];

	for (int i = 0; i < m_m; ++i) {
		temp[i] = new double[m_m];
	}

	return temp;
}

double Matrix::getSize() {
	return this->m_m;
}

void Matrix::printMatrix() const {

	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			cout << this->m_mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::fillMatrix(vector<vector<int>> src) {

	for(int i = 0; i < (int)src.size(); ++i) {
		if (src[i].size() != src.size()) {
			cout << "Matrix is not in mxm size, please check your matrix" << endl;
			exit(-1);
		}	
	}

	for(int i=0; i<m_m; ++i){
		for (int j = 0; j < m_m; ++j) {
			this->m_mat[i][j] = src[i][j];
		}
	}
}

/*
norm -function. 
We calculate the norm using 2-norm of a matrix as it is defined in the article "Matrix norm" on wikipedia, Chapter: "special cases". 
We use 2-norm because that is suggested in the paper "Nineteen dubious ways to compute the exponential of a matrix, twentyfive
years later."
*/
//$$$$$$$$$$$$$$$$$$$$$$$$ We can delete the first for-loops within norm-function and just use the functions within the downloaded package to compute the transpose. Will make the program faster.  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$
double Matrix::norm() const {


	Matrix transpose2(m_m);
	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			transpose2.m_mat[i][j] = this->m_mat[j][i];
		}
	}


	double sum = 0;
	Matrix thisCopy = *this; //calling copy-constructor
	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			for (int k = 0; k < m_m; ++k) {
				sum += thisCopy.m_mat[j][k] * transpose2.m_mat[k][i];
			}
			this->m_mat[j][i] = sum;
			sum = 0;
		}
	}


	//The following is possible due to a package, Eigen, that is downloaded from website www.eigen.tuxfamily.org
	//This package enables us to calculate the eigenvalue of A*transpose(A) matrix in an easy fashion. 
	Eigen::MatrixXd d(m_m, m_m); //dynamic, X,  double matrix of dimension m_m that take real doubles. 
	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			d(i, j) = this->m_mat[i][j]; //filling d matrix.
		}
	}
	Eigen::VectorXd eivals = d.eigenvalues().real(); //Vector that takes all the real eigenvalues of our matrix of interest.
	double sqrtMaxEigen = pow(eivals.maxCoeff(), 0.5); //Squaring the highest eigenvalue.  

	return sqrtMaxEigen; //norm
}



void Matrix::identity() {

	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			this->m_mat[i][j] = 0;
		}
	}

	for (int i = 0; i < m_m; ++i) {
			this->m_mat[i][i] = 1;
	}
}


void Matrix::subtraction(double* expA) {

	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			this->m_mat[i][j] =  m_mat[i][j] - expA[j+i*m_m];
		}
	}
}

Matrix& Matrix::operator+=(const Matrix& Q) {
	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			this->m_mat[i][j] = this->m_mat[i][j] + Q.m_mat[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator=(const Matrix& Q) {
	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			this->m_mat[i][j] = Q.m_mat[i][j];
		}
	}
	return *this;
}






//"this" pointer within the function is copyMatrix. Q is our original A matrix. 
Matrix& Matrix::operator*=(const Matrix& Q) { 
	double sum = 0;

	Matrix thisCopy = *this; //calling copy-constructor
	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			for (int k = 0; k < m_m; ++k) {
					sum += thisCopy.m_mat[j][k] * Q.m_mat[k][i]; 
			}
			this->m_mat[j][i] = sum;
			sum = 0;
		}
	}

	return *this;
}







Matrix& Matrix::operator*=(const double fac) {
	for (int i = 0; i < m_m; ++i) {
		for (int j = 0; j < m_m; ++j) {
			this->m_mat[i][j] =(long double) (this->m_mat[i][j])*fac;
		}
	}
	return *this;

}


//$$$$$$$$$$$$$$$$$$$$$$$$ Instead of making a submatrix, we can use factorial just as in the paper that is refered too.´m "Nineteen dubious ways to compute the exponential of a matrix, twentyfive". 
//Will probably make it faster instead of copying a matrix every time. $$$$$$$$$$$$$$$$$$$$$$$$$$$$$
Matrix Matrix::exp(double* ptr, double tolerance) const {
	int i = 0; double normtest; 

	Matrix copyMatrix = *this; //calling copy constructor. Copying our original matrix object, mat.
	Matrix subMatrix(m_m); //for later tolerance check.
	subMatrix.identity();
	Matrix resultMatrix = subMatrix; //calling copy constructor. ResultMatrix becomes identity matrix.
	Matrix facMatrix(m_m); //Will be the terms of the series. 
	resultMatrix += copyMatrix;// A^0/0! + A^1/1!. Calling operator+=
	subMatrix = resultMatrix; //calling operator=
	subMatrix.subtraction(ptr); //Takes our created exp.Matrix and subtract the expm(A) elements from it. Everything according to T_{K}(A) - expm(A) from paper "Nineteen dubious ways to compute...".
	normtest = 1; // To be able to enter the loop
	i = 2;

	
	while (normtest > tolerance) {
			copyMatrix *= *this; //A^2 for i=2. 
			facMatrix = copyMatrix; //Facmatrix is the terms in the series.

			//Factorial implicitly
			for(int j=0; j<i; j++){
				facMatrix *= ((double)1 / (i-j)); // A^2*(1/2!) for i=2. Callin double operator*=  
			}

			resultMatrix += facMatrix; //Storing the terms in resultMatrix.
			subMatrix = resultMatrix; //Will enable us to calculate the norm
			subMatrix.subtraction(ptr);  // T_{K}(A) - expm(A)
			normtest = subMatrix.norm();// ||T_{K}(A) - expm(A)||
			i++;
	}

	//deallocating the matrix object memory
	//copyMatrix.~Matrix();
	//subMatrix.~Matrix();
	//facMatrix.~Matrix();
	
	return resultMatrix;
}



void getListFromMatrix(double* a, vector<vector<int>> matrix, int sizeOfMatrix) {
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			a[j + i * sizeOfMatrix] = matrix[i][j];
		}
	}
}