#include "Matrices.h"

namespace Matrices {

Matrix::Matrix(int _rows, int _cols) {
  rows = _rows;
  cols = _cols;
  a.resize(rows);
  for (int i = 0; i < rows; i++) {
    a[i].resize(cols, 0.0);
    // a = vector<vector<double>>(rows, vector<double>(cols, 0.0));
  }
}

Matrix operator+(const Matrix &a, const Matrix &b) {
  if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
    throw runtime_error("Error: dimensions must agree");
  }
  Matrix result(a.getRows(), a.getCols());
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getCols(); j++) {
      result(i, j) = a(i, j) + b(i, j);
    }
  }
  return result;
}

Matrix operator*(const Matrix &a, const Matrix &b) {
    if (a.getCols() != b.getRows()) {
        throw runtime_error("Error: dimensions must agree");
    }
  Matrix c(a.getRows(), b.getCols());
  for (int i = 0; i < a.getRows(); i++) {
    for (int k = 0; k < b.getCols(); k++) {
      for (int j = 0; j < a.getCols(); j++) {
        c(i,k) += a(i,j) * b(j,k);
      }
    }
  }
  return c;
}

  bool operator==(const Matrix &a, const Matrix &b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
      return false;
    }
    for (int i = 0; i < a.getRows(); i++) {
      for (int j = 0; j < a.getCols(); j++) {
        if (abs(a(i, j) - b(i, j)) >= 0.001) {
          return false;
        }
      }
    }
    return true;
    // return false;
  }


bool operator!=(const Matrix &a, const Matrix &b) {
  if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
    return true;
  }
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getCols(); j++) {
      if (abs(a(i, j) - b(i, j)) >= 0.001) {
        return true;
      }
    }
  }
  return false;
}

ostream &operator<<(ostream &os, const Matrix &a) {
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getCols(); j++) {
      os << setw(10) << a(i, j);
    }
    cout << endl << endl;
  }

  return os;
}
} // namespace Matrices
