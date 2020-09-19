/**
    main.cpp
    Purpose: Taylor Expansion with Horner's Scheme (Task 1)
    Associated files: taylor.hpp taylor.cpp
    @author Harsha HN harshahn@kth.se, Aron Andersson aronande@kth.se
    @version 1.0 22 sept 2019
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "taylor.hpp"
#define clrscr() cout << "\033[2J\033[1;1H"; //To clear the console
using namespace std;

int main() {
    clrscr();
    double result; 
	int listN[] = { 5, 10, 50, 100}; //list of num of terms
	int listX[] = {-1, 1, 2, 3, 5, 10}; //list of angles

//printing out the lists. 
	cout << "\n" << "---Task 1: Taylor Expansion with Horner's Scheme---" << "\n";

// Taylor's calculation	
	double x=0.0; int N=0;
    double sinerr=0.0, coserr=0.0; //absolute errors
	for (int i = 0; i < 4; i++) { // 4
		N = listN[i]; cout << "Config N = " << N << endl;

		for (int j = 0; j < 6; j++) { // 6
			x = listX[j]; cout << "  For x = " << x << endl;
			//Sine function
			sinerr = abs(sin(x) - sinTaylor(N, x));
			cout << "    sin func: error = " << setw(11) << sinerr
			<< "  N+1-term = " << abs(sinTaylor(N + 1, x)) << endl;
            //Cosine function
            coserr = abs(cos(x) - cosTaylor(N, x));
			cout << "    cos func: error = " << setw(11) << coserr
			<< "  N+1-term = " << abs(cosTaylor(N + 1, x)) << endl;
		}
		cout << "\n";
	}

    return 0;
}
