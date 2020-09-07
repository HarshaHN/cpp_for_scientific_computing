


/*
IMPORTANT NOTE.
From www.eigen.tuxfamily.org we downloaded the latest release,
Eigen 3.3.7, which makes calculation of eigenvalues simple by #include <Eigen>. 
1. Download the package.
2. If u use GNU. Please write in the terminal, g++ -Wall -I /Users/HP/Downloads/eigen-eigen-323c052e1731/eigen-eigen-323c052e1731/ task2MatrixProject2main.cpp task2Project2.cpp r8lib.cpp r8mat_expm1.cpp -o output
*/

#include <iostream>
#include <vector>
#include "task2Project2.hpp"
using namespace std;
#include "r8lib.h"

double* r8mat_expm1(int m, double a[]); //from file


int main() {

	//The user creates mxm integer matrices of whatever size. 

	
	vector<vector<int>> srcA = {{2,0,1},
								{-1,1,0},
								{-3,3,0} }; 
	
	
	
	vector<vector<int>> srcB = {{5,6},
						        {4,2}};
	
	vector<vector<int>> srcC = { {5,4,4,3,3,7},
							     {0,2,2,3,4,1},
							     {9,8,3,2,2,2},
	                             {0,2,2,3,4,1},
							     {0,2,2,3,4,1},
							     {0,2,2,3,4,1}};
	
	vector<vector<vector<int>>> listOfMatrices = {srcA, srcB, srcC};

	for (auto element : listOfMatrices) {

		Matrix mat(element.size()); //allocating memory for a mxm matrix object
		mat.fillMatrix(element);  //Assigning the values in srcA to matA matrix. If
		//srcA fails to be a mxm matrix we will get an error message. 
		int size = mat.getSize();
		double a[size * size];
		getListFromMatrix(a, element, size);

		//expm(A) from the files given.
		//$$$$$$$$$$$$$$$$$$$$$$$$ We can test the file with EOF and stuff we learned of on that lecture? Or atleast make an error message if the file can´t be read $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		double* cExpm;
		cExpm = r8mat_expm1(size, a);
		double tol = 0.1;

		//$$$$$$$$$$$$$$$$$$$$$$$$ Can be made to a move constructor to effectivize $$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		Matrix resultOfExpTaylor = mat.exp(cExpm, tol); //Expm will be help us to to minimize error, tol is tolerance.


		//Presenting our matrix
		cout << "\n" << "\n" << "\n" << "Our created matrix is: " << endl;
		mat.printMatrix();

		cout << "The expm(A) matrix from files given to us is: " << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << cExpm[j + i * size] << " ";
			}
			cout << endl;
		}

		cout << "\n" << "Our approximated exponential of out created matrix, with tolerance " << tol << ", is: " << endl;
		resultOfExpTaylor.printMatrix();

		//$$$$$$$$$$$$$$$$$$$$$$$$ Deconstructors. Can be placed at right locations to effectivize the program $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		//deallocating memory
		//delete[] cExpm; 
		//mat.~Matrix(); 
		//resultOfExpTaylor.~Matrix();

	}

}   


