/**
    taylor.hpp
    Purpose: Header file to compute sine and cosine values 
    using Taylor's series and horner's scheme.

    @author Harsha HN harshahn@kth.se, Aron Andersson aronande@kth.se
    @version 1.0 22 sept 2019
*/

#ifndef TAYLOR_HPP
#define TAYLOR_HPP
    /**
        Returns the value of horner's equation

        @param  c[]: co-efficient of horner's equation
                x: angle in radians
                N: number of terms
        @return horner's equation value
    */
    double horner(int c[], double x, int N);

    /**
        Returns sin(x) upto N terms using Taylor's series

        @param  N: num of terms in the Taylor's series
                x: angle in radians
        @return sine value
    */
    double sinTaylor(int N, double x); 

    /**
        Returns cos(x) upto N terms using Taylor's series

        @param  N: num of terms in the Taylor's series
                x: angle in radians
        @return cosine value
    */
    double cosTaylor(int N, double x);
#endif