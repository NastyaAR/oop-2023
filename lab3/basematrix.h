#ifndef BASEMATRIX_H
#define BASEMATRIX_H

#include "matrix.h"

class BaseMatrix
{
public:
	BaseMatrix(Matrix<double> &matrix) : mtr(matrix) {};
	~BaseMatrix() = default;

	Matrix<double> &getMatrix() { return mtr; };
	Matrix<double> &getMatrix() const { return mtr; };
private:
	Matrix<double> &mtr;
};

#endif // BASEMATRIX_H
