/**
    asi.hpp
    Purpose: Header file to compute integral using ASI

    @author Aron Andersson aronande@kth.se, Harsha HN harshahn@kth.se
    @version 1.0 22 sept 2019
*/

#ifndef ASI_HPP
#define ASI_HPP

/**
    Pointer to function
*/
typedef double (*FunctionPointer)(double);

/**
    Returns fully ASI
    @param  f: pointer to function
            a, b: from a to b
            tol: acceptable tolerance
    @return fully ASI value
*/
double ASI(FunctionPointer f, double a, double b, double tol);

/**
    Returns computed integral from a to b using Simpson rule
    @param  f: pointer to function
            aa, bb: from a to b
    @return ASI value
*/
double I(FunctionPointer f, double aa, double bb);

#endif
