#ifndef TASK2PROJECT2_HPP
#define TASK2PROJECT2_HPP
#include <vector>


class Matrix {
private:
	int dim;

	// We can make it a pointer do a double instead to effectivize. Almost every for-loop needs then to be changed. $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	double** mat; 

public:
	//constructor that creates an empty mxm matrix. 
	Matrix(int m) : dim(m) {
		this->mat = generateMatrix(this->dim);
	}

	double getSize(); //gets size, dim,  of matrix

	//copy constructor. It creates a copy of our other matrix
	Matrix(const Matrix& Other): dim(Other.dim) {

		this->mat = generateMatrix(this->dim);
		for (int i = 0; i < dim; ++i) {
			for (int j = 0; j < dim; ++j) {
				this->mat[i][j] = Other.mat[i][j];
			}
		}

	}



	double** generateMatrix(int dim);
	void printMatrix() const;
	void fillMatrix(std::vector<std::vector<int>> src);
	Matrix& operator+=(const Matrix& Q); //Adding of matrices
	Matrix& operator=(const Matrix& Q); //Setting a previous created matrix-object equal to another previous created matrix-object
	Matrix& operator*=(const Matrix& Q); //multiplication of matrices
	Matrix& operator*=(const double fac); //multiplicate a matrix by a double. 

	//2-norm function. 
	double norm() const; 

	//Identity matrix.
	//Is used to create first object matrix, A^0/0!, in the series of creating an approximation of the exponential of a matrix. 
	//A^0/0! = Identity matrix. 
	void identity(); 


	//Subtraction function.
	//Is used in a later step to be able to calculate norm of ||T_{K}(A) - exp(A)||. That is, subtraction function
	//is taking a matrix object, T_{K}(A), that is made for every loop in the process of creating our own approximation 
	//of exponential of a matrix, then we take T_{K}(A) matrix object and subtract with elements of expm(A), which is an array (not an object from a class).
	//Expm(A) is calculated from the files that we were given, which is the most
	//accurate way we have to calculate exponential of a matrix, and we will use this, with the help of a tolerance, to
	//calculate our own exponential of matrix. 
	void subtraction(double* expA); 

	//Exponential of a matrix function.
	//Calculating the exponential of our matrix.
	//ptr is a pointer to a C-style array holding the exponential of a matrix, expm(A), in Fortran style.
	//Expm(A) will be used for error check with given tolerance. 
	Matrix exp(double* ptr, double tolerance) const; 
	
	//Deconstructor, deleteting the matrix 
	~Matrix();

};


//Taking values from our matrix and make it into a C-style array . 
void getListFromMatrix(double* a, std::vector<std::vector<int>> matrix, int sizeOfMatrix);


#endif