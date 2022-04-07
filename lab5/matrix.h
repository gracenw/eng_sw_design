#ifndef MATRIX_H
#define MATRIX_H
#include "complex.h"
#include <string>
#define MATRIX_FIELD 30

class Matrix;
ostream& operator<<(ostream&, const Matrix&);
Matrix operator*(Complex, const Matrix &);
Matrix operator*(const Matrix&, Complex);
class Matrix {
	public:
		Matrix(int, int);
		Matrix(const Matrix&);
		~Matrix();
		Complex& operator()(int, int);
		void operator=(const Matrix&);
		Matrix operator+(const Matrix&);
		Matrix operator-(const Matrix&);
		Matrix operator*(const Matrix&);
		void transpose();
		Matrix operator~();
		Matrix operator!();
		void printMatrix();
		friend ostream& operator<<(ostream&, const Matrix&);
		friend Matrix operator*(Complex, const Matrix&);
		friend Matrix operator*(const Matrix&, Complex);
	private:
		int rows;
		int cols;
		Complex* matrix;
};

#endif
