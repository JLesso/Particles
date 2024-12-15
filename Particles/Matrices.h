#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

namespace Matrices
{
    class Matrix
    {
        public:
            ///Construct a matrix of the specified size.
            ///Initialize each element to 0.
            Matrix(int _rows, int _cols);

            ///************************************
            ///inline accessors / mutators, these are done:

            ///Read element at row i, column j
            ///usage:  double x = a(i,j);
            const double& operator()(int i, int j) const
            {
                return a.at(i).at(j);
            }

            ///Assign element at row i, column j
            ///usage:  a(i,j) = x;
            double& operator()(int i, int j)
            {
                //return a[i][j];
                return a.at(i).at(j);
            }


            int getRows() const{return rows;}
            int getCols() const{return cols;}
            ///************************************

        private:
            vector<vector<double>> a;
            int rows;
            int cols;
    };

    ///Add each corresponding element.
    ///usage:  c = a + b;
    Matrix operator+(const Matrix& a, const Matrix& b);

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b);

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b);

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b);

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a);
    class RotationMatrix : public Matrix
    {
    public:
        RotationMatrix(double theta) : Matrix(2, 2) {
            (*this)(0, 0) = cos(theta);
            (*this)(0, 1) = -sin(theta);
            (*this)(1, 0) = sin(theta);
            (*this)(1, 1) = cos(theta);
        }
    };
    class ScalingMatrix : public Matrix
    {
    public:
        ScalingMatrix(double scale) : Matrix(2, 2) {
            (*this)(0, 0) = scale;  (*this)(0, 1) = 0;
            (*this)(1, 0) = 0;      (*this)(1, 1) = scale;
        }
    };

    class TranslationMatrix : public Matrix
    {
    public:
        TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols) {
            for (int i = 0; i < nCols; ++i) {
                (*this)(0, i) = xShift;
                (*this)(1, i) = yShift;
            }
        }
    };
}

#endif // MATRIX_H_INCLUDED
