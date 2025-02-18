#pragma once

#include "matrix.hh"
#include <math.h>

typedef Matrix<double,3> matrix3d;

class matrixrot: public matrix3d
{
public:
matrixrot()
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 1;
    (*this)(1,2) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
}


void wypelnijRotX(matrix3d &m, double theta)
    {
    theta *= 3.14/180;         
    m(0,0) = 1;
    m(0,1) = 0;
    m(0,2)= 0;

    m(1,0) = 0;
    m(1,1)= cos(theta);
    m(1,2) = -sin(theta);

    m(2,0) = 0;
    m(2,1) = sin(theta);
    m(2,2) = cos(theta);
    }

void wypelnijRotY(matrix3d &m, double theta)
{
    theta *= 3.14/180;         
    m(0,0) = cos(theta);
    m(0,1) = 0;
    m(0,2)= sin(theta);

    m(1,0) = 0;
    m(1,1)= 1;
    m(1,2) = 0;

    m(2,0) = -sin(theta);
    m(2,1) = 0;
    m(2,2) = cos(theta);
}

void wypelnijRotZ(matrix3d &m, double theta)
{
    theta *= 3.14/180;         
    m(0,0) = cos(theta);
    m(0,1) = -sin(theta);
    m(0,2)= 0;

    m(1,0) = sin(theta);
    m(1,1)= cos(theta);
    m(1,2) = 0;
    
    m(2,0) = 0;
    m(2,1) = 0;
    m(2,2) = 1;
}
};
