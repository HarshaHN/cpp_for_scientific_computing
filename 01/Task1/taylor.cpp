/**
    taylor.cpp
    Purpose: To compute sine and cosine values using Taylor's series
    and horner's method.
    Associated files: taylor.hpp
    @author Harsha HN harshahn@kth.se, Aron Andersson aronande@kth.se
    @version 1.0 22 sept 2019
*/

#include "taylor.hpp"

//Returns the value of horner's equation 
double horner(int c[], double x, int N){

    double res = 0.0; //result value
    res = c[N-1];
    for (int i=N-1; i>0; i--){
        res = c[i-1] + x*res/i; //recursive eval of cn-1 +x*cn
    }
    return res;
}

//Returns sin(x) upto N terms using Taylor's series
double sinTaylor(int N, double x){
	double result = 0.0; //result value
	//Generate co-efficients sequence
	int *c = new int[2*N]; //N terms imply 2*N in horner equation
	for (int i=0; i<2*N; i++)
        c[i] = (((1 + i) % 2 == 0) ? (2 - (i % 4)) : 0); // Generates 0 1 0 -1 0...
	//Call horner with c, x and 2*N
	result = horner(c, x, 2*N);
	return result;
}

 //cos(x) upto N terms using Taylor's series
double cosTaylor(int N, double x){
	double result = 0.0; //result value
	//Generate co-efficients sequence
	int *c = new int[2*N-1]; //N terms imply 2*N-1 in horner equation
	for (int i=0; i<(2*N-1); i++){
        c[i] = (( i % 2 == 0) ? 1 - (i % 4)  : 0); // Generates 1 0 -1 0 1...
        }
	//Call horner with c, x and 2*N-1
	result = horner(c, x, 2*N-1);
	return result;
}