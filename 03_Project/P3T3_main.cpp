#include <iostream>
#include "domain.hpp"
#include "Curvebase.hpp"
#include "BottomFunction.hpp"
#include "StraightYlineBoundary.hpp"
#include "StraightXLineBoundary.hpp"
using namespace std;

/*
Write the following in the terminal.
g++ -Wall P3T3_main.cpp domain.cpp Curvebase.cpp BottomFunction.cpp StraightXLineBoundary.cpp StraightYLineBoundary.cpp -o output
*/

int main() {

	/*
	Task 3
	*/
	BottomFunction bottomFunc = BottomFunction(-10, 5); //Bottom curve of the domain, from x=-10 to x=5.
	StraightYLineBoundary  yLineRight = StraightYLineBoundary(0, 3, 5); //y-values from 0 to 3, x-value constant 5.
	StraightXLineBoundary  xTopLine = StraightXLineBoundary(-10, 5, 3); // x-values from -10 to 5, y-value constant 3.
	StraightYLineBoundary  yLineLeft = StraightYLineBoundary(0, 3, -10); // y-values from 0 to 3, x-value constant -10.

	Domain domainTest = Domain(bottomFunc, yLineRight, xTopLine, yLineLeft);
	int m = 50; int n = 20;
	domainTest.generate_grid(m, n);

	//Task 4
	domainTest.writeToFile(); //then we use matlab to plot the .bin files 

}
