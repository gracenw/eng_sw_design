#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
using namespace std;

class Complex;
ostream& operator<<(ostream&, const Complex&);
class Complex {
	public:
		Complex();
		Complex(double);
		Complex(double, double);
		void setReal(double);
		double getReal();
		void setImag(double);
		double getImag();
		void setNaN(bool);
		bool getNaN();
		Complex operator+(const Complex&);
		Complex operator-(const Complex&);
		Complex operator*(const Complex&);
		Complex operator/(const Complex&);
		void displayPolar();
		void displayRect();
		void setComplex(double, double);
		friend ostream& operator<<(ostream&, const Complex&);
	private:
		double real;
		double imag;
		bool NaN;
};

#endif
