/*
Project 3, task 2:
Test the classes by using it in
a simple main program.

Input argument s is arc length coordinate expressed in normalized coordinate

g++ -Wall P3T2_main.cpp Curvebase.cpp BottomFunction.cpp StraightXLineBoundary.cpp StraightYLineBoundary.cpp -o output
*/


#include <iostream>
#include "Curvebase.hpp"
#include "BottomFunction.hpp"
#include "StraightYlineBoundary.hpp"
#include "StraightXLineBoundary.hpp"


using namespace std;


int main() {

	StraightYLineBoundary  yLineLeft = StraightYLineBoundary(0, 3, -10); // y-values from 0 to 3, x-value constant -10.
	StraightYLineBoundary  yLineRight = StraightYLineBoundary(0, 3, 5); //y-values from 0 to 3, x-value constant 5.
	StraightXLineBoundary  xTopLine = StraightXLineBoundary(-10, 5, 3); // x-values from -10 to 5, y-value constant 3.
	BottomFunction bottomFunc = BottomFunction(-10, 5); //Bottom curve of the domain, from x=-10 to x=5.

	
	//Corners
	cout << "\n" << "------------The corners of the domain-----------" << endl;
	double xValueLeft = yLineLeft.x(0); //x constant
	double yLeftUpperCorner = yLineLeft.y(1);
	cout << "The (x-value, y-value) of left upper corner:  (" << xValueLeft << ", " << yLeftUpperCorner << ")" << endl;
	double xValueRight = yLineRight.x(1); //x constant
	double yRightUpperCorner = yLineRight.y(1);
	cout << "The (x-value, y-value) of right upper corner:  (" << xValueRight << ", " << yRightUpperCorner << ")" << endl;
	double yRightbottomCorner = yLineRight.y(0);
	cout << "The (x-value, y-value) of right bottom corner:  (" << xValueRight << ", " << yRightbottomCorner << ")" << endl;
	double yLeftbottomCorner = yLineLeft.y(0);
	cout << "The (x-value, y-value) of left bottom corner:  (" << xValueLeft << ", " << yLeftbottomCorner << ")" << endl;

	
	//Some x-values along the upper straight line
	cout << "\n" << "------------Some x-values along upper straight line-----------" << endl;
	double yValueu = xTopLine.y(0.33); //x-value constant
	double xValue0u = xTopLine.x(0); double xValue1u = xTopLine.x(0.25); double xValue2u = xTopLine.x(0.5); double xValue3u = xTopLine.x(0.75); double xValue4u = xTopLine.x(1);
	cout << "s-value 0 is equivalent to the coordinates:  (" << xValue0u << ", " << yValueu << ")" << endl;
	cout << "s-value 0.25 is equivalent to the coordinates:  (" << xValue1u << ", " << yValueu << ")" << endl;
	cout << "s-value 0.50 is equivalent to the coordinates:  (" << xValue2u << ", " << yValueu << ")" << endl;
	cout << "s-value 0.75 is equivalent to the coordinates:  (" << xValue3u << ", " << yValueu << ")" << endl;
	cout << "s-value 1.0 is equivalent to the coordinates:  (" << xValue4u << ", " << yValueu << ")" << endl;
	


	//Some x-values and y-values along the bottom function curve
	cout << "\n" << "------------Some x-values and y-values along bottom curve-----------" << endl;
	double yValueb0 = bottomFunc.y(0); //y-value NOT constant
	double xValueb0 = bottomFunc.x(0); 
	cout << "s-value 0 is equivalent to the coordinates:  (" << xValueb0 << ", " << yValueb0 << ")" << endl;
	double yValueb1 = bottomFunc.y(0.25);
	double xValueb1 = bottomFunc.x(0.25); 
	cout << "s-value 0.25 is equivalent to the coordinates:  (" << xValueb1 << ", " << yValueb1 << ")" << endl;
	double yValueb2 = bottomFunc.y(0.5); 
	double xValueb2 = bottomFunc.x(0.5);
	cout << "s-value 0.50 is equivalent to the coordinates:  (" << xValueb2 << ", " << yValueb2 << ")" << endl;
	double yValueb3 = bottomFunc.y(0.75);  
	double xValueb3 = bottomFunc.x(0.75); 
	cout << "s-value 0.75 is equivalent to the coordinates:  (" << xValueb3 << ", " << yValueb3 << ")" << endl;
	double yValueb4 = bottomFunc.y(1); 
	double xValueb4 = bottomFunc.x(1);
	cout << "s-value 1 is equivalent to the coordinates:  (" << xValueb4 << ", " << yValueb4 << ")" << endl;


	//Some y-values along the left y curve
	cout << "\n" << "------------Some y-values along the left y curve-----------" << endl;
	double xValueu = yLineLeft.x(0); //x-value constant
	double yValue0u = yLineLeft.y(0); double yValue1u = yLineLeft.y(0.25); double yValue2u = yLineLeft.y(0.5); double yValue3u = yLineLeft.y(0.75); double yValue4u = yLineLeft.y(1);
	cout << "s-value 0 is equivalent to the coordinates:  (" << xValueu << ", " << yValue0u << ")" << endl;
	cout << "s-value 0.25 is equivalent to the coordinates:  (" << xValueu << ", " << yValue1u << ")" << endl;
	cout << "s-value 0.50 is equivalent to the coordinates:  (" << xValueu << ", " << yValue2u << ")" << endl;
	cout << "s-value 0.75 is equivalent to the coordinates:  (" << xValueu << ", " << yValue3u << ")" << endl;
	cout << "s-value 1.0 is equivalent to the coordinates:  (" << xValueu << ", " << yValue4u << ")" << endl;

	//Some y-values along the right y curve
	cout << "\n" << "------------Some y-values along the right y curve-----------" << endl;
	double xValueur = yLineRight.x(0); //x-value constant
	double yValue0ur = yLineRight.y(0); double yValue1ur = yLineRight.y(0.25); double yValue2ur = yLineRight.y(0.5); double yValue3ur = yLineRight.y(0.75); double yValue4ur = yLineRight.y(1);
	cout << "s-value 0 is equivalent to the coordinates:  (" << xValueur << ", " << yValue0ur << ")" << endl;
	cout << "s-value 0.25 is equivalent to the coordinates:  (" << xValueur << ", " << yValue1ur << ")" << endl;
	cout << "s-value 0.50 is equivalent to the coordinates:  (" << xValueur << ", " << yValue2ur << ")" << endl;
	cout << "s-value 0.75 is equivalent to the coordinates:  (" << xValueur << ", " << yValue3ur << ")" << endl;
	cout << "s-value 1.0 is equivalent to the coordinates:  (" << xValueur << ", " << yValue4ur << ")" << endl;


}