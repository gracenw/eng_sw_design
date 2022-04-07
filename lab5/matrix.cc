#include "matrix.h"

//constructors
Matrix::Matrix(int r, int c) {
  rows = r;
  cols = c;
  if(rows == 0) matrix = NULL;
  else {
    matrix = new Complex[(rows * cols)];
    for(int i = 0; i < (rows * cols); i++) {
      matrix[i] = Complex();
    }
  }
};

Matrix::Matrix(const Matrix& tocopy) {
  rows = tocopy.rows;
  cols = tocopy.cols;
  matrix = new Complex[(rows * cols)];
  for(int i = 0; i < (rows * cols); i++) {
    matrix[i] = tocopy.matrix[i];
  }
};

//destructor
Matrix::~Matrix() {
  if(matrix != NULL) delete [] matrix;
};

//member functions
Complex& Matrix::operator()(int r, int c) {
  int index = (r * this->cols) - (this->cols - c) - 1;
  return this->matrix[index];
}

void Matrix::operator=(const Matrix& RHS) {
  this->rows = RHS.rows;
  this->cols = RHS.cols;
  delete [] this->matrix;
  this->matrix = new Complex[(this->rows * this->cols)];
  for(int i = 0; i < (this->rows * this->cols); i++) {
    matrix[i] = RHS.matrix[i];
  }
}

Matrix Matrix::operator+(const Matrix& RHS) {
  if(this->rows != RHS.rows && this->cols != RHS.cols) {
    Matrix temp(0,0);
    cout << "Matrix Mismatch Error!" << endl;
    return temp;
  }
  else {
    Matrix temp(this->rows, this->cols);
    for(int i = 0; i < (this->rows * this->cols); i++) {
      temp.matrix[i] = this->matrix[i] + RHS.matrix[i];
    }
    return temp;
  }
}

Matrix Matrix::operator-(const Matrix& RHS) {
  if(this->rows != RHS.rows && this->cols != RHS.cols) {
    Matrix temp(0,0);
    cout << "Matrix Mismatch Error!" << endl;
    return temp;
  }
  else {
    Matrix temp(this->rows, this->cols);
    for(int i = 0; i < (this->rows * this->cols); i++) {
      temp.matrix[i] = this->matrix[i] - RHS.matrix[i];
    }
    return temp;
  }
}

Matrix Matrix::operator*(const Matrix& RHS) {
  if(this->cols != RHS.rows) {
    Matrix temp(0,0);
    cout << "Matrix Mismatch Error!" << endl;
    return temp;
  }
  else {
    Matrix temp(this->rows, RHS.cols);
    for(int r = 1; r <=  this->rows; r++) {
      for(int c = 1; c <= RHS.cols; c++) {
        Complex sum(0,0);
        for(int i = 1; i <= RHS.rows; i++) {
          int this_index = (r * this->cols) - (this->cols - i) - 1;
          int rhs_index = (i * RHS.cols) - (RHS.cols - c) - 1;
          Complex product(0,0);
          product = this->matrix[this_index] * RHS.matrix[rhs_index];
          sum = sum + product;
        }
        int temp_index = (r * temp.cols) - (temp.cols - c) - 1;
        temp.matrix[temp_index] = sum;
      }
    }
    return temp;
  }
}

void Matrix::transpose() {
  //assuming square matrix based on main.cc
  Matrix copy(this->rows, this->cols);
  for(int i = 0; i < (copy.rows * copy.cols); i++) {
    copy.matrix[i] = this->matrix[i];
  }
  for(int r = 1; r <= this->rows; r++) {
    for(int c = 1; c <= this->cols; c++) {
      int this_index = (r * this->cols) - (this->cols - c) - 1;
      int copy_index = (c * this->cols) - (this->cols - r) - 1;
      this->matrix[this_index] = copy.matrix[copy_index];
    }
  }
}

Matrix Matrix::operator~() {
  //assuming square matrix based on main.cc
  Matrix temp(this->rows, this->cols);
  for(int r = 1; r <= this->rows; r++) {
    for(int c = 1; c <= this->cols; c++) {
      int temp_index = (r * this->cols) - (this->cols - c) - 1;
      int this_index = (c * this->cols) - (this->cols - r) - 1;
      temp.matrix[temp_index] = this->matrix[this_index];
    }
  }
  return temp;
}

Matrix Matrix::operator!() {
  //assuming square matrix based on main.cc
  Matrix temp(this->rows, this->cols);
  for(int i = 0; i < (temp.rows * temp.cols); i++) {
    temp.matrix[i] = this->matrix[i];
    int imag = temp.matrix[i].getImag();
    if(imag != 0) temp.matrix[i].setImag(-imag);
  }
  temp.transpose();
  return temp;
}

void Matrix::printMatrix() {
  if(this->rows == 0) cout << "This matrix has zero elements" << endl;
  else {
    for(int i = 0; i < (this->rows * this->cols); i++) {
      cout << this->matrix[i];
      if((i+1) % this->cols == 0) cout << endl;
      else cout<< "\t\t";
    }
  }
}

//friend functions
ostream& operator<<(ostream& out, const Matrix& RHS) {
  if(RHS.rows == 0) out << "This matrix has zero elements" << endl;
  else {
    for(int i = 0; i < (RHS.rows * RHS.cols); i++) {
      out << RHS.matrix[i];
      if((i+1) % RHS.cols == 0) out << endl;
      else out << "\t\t";
    }
  }
  return out;
}

Matrix operator*(Complex LHS, const Matrix& RHS) {
  Matrix temp(RHS.rows,RHS.cols);
  for(int i = 0; i < (RHS.rows * RHS.cols); i++) {
    temp.matrix[i] = RHS.matrix[i] * LHS;
  }
  return temp;
}

Matrix operator*(const Matrix& LHS, Complex RHS) {
  Matrix temp(LHS.rows,LHS.cols);
  for(int i = 0; i < (LHS.rows * LHS.cols); i++) {
    temp.matrix[i] = LHS.matrix[i] * RHS;
  }
  return temp;
}
