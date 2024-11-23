#include <iostream>

using namespace std;

class Matrix {
public:
    int row, col;
    double** c;
    void create(int _row, int _col) {
        row = _row; col = _col;
        c = new double*[row];
        for(int i = 0; i < row; i++) {
            c[i] = new double[col];
        }
    }
    Matrix(int _row, int _col) { create(_row, _col); }
    void free() {
        for(int i = 0; i < row; i++) {
            delete[] c[i];
        }
        delete[] c;
        c = nullptr;
        row = col = 0;
    }
    ~Matrix() { free(); }
    double& operator()(int i, int j) {
        return c[i][j];
    }
    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for(int i = 0; i < matrix.row; i++) {
            for(int j = 0; j < matrix.col; j++) {
                os << matrix.c[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& is, Matrix& matrix) {
        for(int i = 0; i < matrix.row; i++) {
            for(int j = 0; j < matrix.col; j++) {
                is >> matrix.c[i][j];
            }
        }
        return is;
    }
    Matrix& operator+=(const Matrix& matrix) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                c[i][j] += matrix.c[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& matrix) { //row * col  col * matrix.col
        int m = row, n = col, p = matrix.col;
        Matrix tmp(m, p);
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < p; j++) {
                    tmp.c[i][j] += c[i][k] * matrix.c[k][j];
                }
            }
        }
        free(); create(m, p);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p; j++) {
                c[i][j] = tmp.c[i][j];
            }
        }
        return *this;
    }
    Matrix& operator=(const Matrix& matrix) {
        free();
        create(matrix.row, matrix.col);
        for(int i = 0; i < matrix.row; i++) {
            for(int j = 0; j < matrix.col; j++) {
                c[i][j] = matrix.c[i][j];
            }
        }
        return *this;
    }
};
int row1, row2, col1, col2;

int main() {
    cin >> row1 >> col1;
    Matrix A(row1, col1);
    cin >> A;
    
    cin >> row2 >> col2;
    Matrix B(row2, col2);
    cin >> B;

    cout << A(row1/2, col1/2) << endl;
    if(A.col != B.row) cout << "ERROR!\n";
    else cout << (A *= B);
    if(A.row != B.row || A.col != B.col) cout << "ERROR!\n";
    else cout << (A += B);
    cout << (A = B);
    return 0;
}
