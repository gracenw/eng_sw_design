#include "complex.h"

//constructors
Complex::Complex(): real(0.0), imag(0.0), NaN(false) {};
Complex::Complex(double u): real(u), imag(0.0), NaN(false) {};
Complex::Complex(double u, double v): real(u), imag(v), NaN(false) {};

//member functions
void Complex::setReal(double u) { real = u; }

double Complex::getReal() { return real; }

void Complex::setImag(double v) { imag = v; }

double Complex::getImag() { return imag; }

void Complex::setNaN(bool n) { NaN = n; }

bool Complex::getNaN() { return NaN; }

Complex Complex::operator+(const Complex& RHS) {
  Complex sum;
  sum.real = this->real + RHS.real;
  sum.imag = this->imag + RHS.imag;
  return(sum);
}

Complex Complex::operator-(const Complex& RHS) {
  Complex difference;
  difference.real = this->real - RHS.real;
  difference.imag = this->imag - RHS.imag;
  return(difference);
}

Complex Complex::operator*(const Complex& RHS) {
  Complex product;
  product.real = this->real * RHS.real - this->imag * RHS.imag;
  product.imag = this->real * RHS.imag + this->imag * RHS.real;
  return(product);
}

Complex Complex::operator/(const Complex& RHS) {
  Complex quotient;
  double num_real = this->real * RHS.real - this->imag * (-RHS.imag);
  double num_imag = this->real * (-RHS.imag) + this->imag * RHS.real;
  double denom = pow(RHS.real, 2) + pow( (-RHS.imag), 2);
  if(denom == 0.0) quotient.NaN = true;
  else {
    quotient.real = num_real / denom;
    quotient.imag = num_imag / denom;
  }
  return(quotient);
}

void Complex::displayPolar() {
  if(NaN == true) cout << "NaN" << endl;
  else  {
    double r = sqrt( (pow(this->real, 2) + pow(this->imag, 2)) );
    double theta = atan2(this->imag, this->real);
    cout << r << " < " << theta << endl;
  }
}

void Complex::displayRect() {
  if(this->NaN == true) cout << "NaN" << endl;
  else if(this->real == 0.0 && this->imag == 0.0) cout << "0.0" << endl;
  else if(this->real == 0.0) cout << this->imag << "j" << endl;
  else if(this->imag == 0.0) cout << this->real << endl;
  else cout << this->real << " + " << this->imag << "j" << endl;
}

void Complex::setComplex(double u, double v) {
  this->real = u;
  this->imag = v;
}

//friend functions
ostream& operator<<(ostream& out, const Complex& RHS) {
  if(RHS.NaN == true) out << "NaN";
  else if(RHS.real == 0.0 && RHS.imag == 0.0) out << "0";
  else if(RHS.real == 0.0) out << RHS.imag << "j";
  else if(RHS.imag == 0.0) out << RHS.real;
  else out << RHS.real << " + " << RHS.imag << "j";
  return out;
}
