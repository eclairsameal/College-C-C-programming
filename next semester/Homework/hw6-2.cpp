//檔名:hw6-2.c
//編譯器:Dev-c++
//日期:2011/6/4 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Matrix{
public:
  Matrix(unsigned int _m = 0, unsigned int _n = 0){
    setMatrix(_m, _n);
  }
  void setMatrix(unsigned int _m = 0, unsigned int _n = 0){
    m = _m;
    n = _n;
    mat = new int *[m];
    for(int i = 0; i < m; i++)mat[i] = new int [n];
  }
  void setnu(int im, int in, int anu){
    mat[im][in] = anu;     
  } 
  int getM(){return m;}
  int getN(){return n;}
  void inputMatrix(){
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
      cin >> mat[i][j];
      }
    }  
  }//輸入矩陣
  void printf_Matrix(){
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cout << setw(4) << mat[i][j];
      }
      cout << "\n";
    }
  }//列印矩陣 
  bool dadd_Matrix(Matrix ma, Matrix mb){
    if(ma.m == mb.m && ma.n == mb.n) return true;
    else return false;  
  }//判斷兩矩陣是否可相加 
  Matrix operator+(Matrix ma){
    Matrix sum(m, n);
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        sum.setnu(i, j, ma.mat[i][j] + mat[i][j]);
      }
    }
    return sum;
  }//+ 多載兩矩陣相加 
  bool multiplication(Matrix ma, Matrix mb){
    if(ma.n == mb.m)return true;
    else return false;    
  }//判斷兩矩陣是否可相乘 
  Matrix operator*(Matrix ma){
    Matrix sum(m, ma.n);
    int temp = 0;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < ma.n; j++){
        temp = 0;
        for(int k = 0; k < n; k++){
          temp+= mat[i][k] * ma.mat[k][j];
        }
        sum.setnu(i, j, temp);
      }
    }
    return sum;
  } //* 多載兩矩陣相乘 
private:
  unsigned int m, n; 
  int **mat; 
};

int main(){
  unsigned int ma, na, mb, nb;
  Matrix addmatrix, sum;
  cout << "Enter the Matrix A size:";
  cin >> ma >> na;
  Matrix Matrix_a(ma, na);
  Matrix_a.inputMatrix();
  cout << "Enter the Matrix B size:";
  cin >> mb >> nb;
  Matrix Matrix_b(mb, nb);
  Matrix_b.inputMatrix();
  cout << "Matrix A:\n";
  Matrix_a.printf_Matrix();
  cout << "Matrix B:\n";
  Matrix_b.printf_Matrix();
  if(Matrix_a.dadd_Matrix(Matrix_a, Matrix_b)){
    addmatrix = Matrix_a + Matrix_b;
    cout << "The result of Matrix A + B is:\n";
    addmatrix.printf_Matrix();
    cout << "\n";                          
  }
  else cout << "A and B cannot be added because the dimensions of the matricesare different.\n\n";
  if(Matrix_a.multiplication(Matrix_a, Matrix_b)){
    sum = Matrix_a * Matrix_b;
    cout << "The result of Matrix A x B is:\n";
    sum.printf_Matrix();
    cout << "\n";
  } 
  else cout << "A and B cannot be multiplied because the columns of the first matrix must be equal to the rows of the second one.\n";  
  system("pause");
}
/*
Define a matrix and its operations.
1. Constructor and destructor summary:
	1. Matrix(usigned int m, unsigned n): construct a matrix of m by n.
		Hint: for (int i = 0; i < m; i++) mp[i] = new int[n];
	2. ~Matrix(): desctruct a matrix.
2. Member function summary:
	1. Matrix operator+(Matrix m2): addition of two matrices.
	2. Matrix operator*(Matrix m2): multiplication of two matrices.
	3. string str(): return the matrix as a string in the form of
		1  2  3  4            5  6  7  8            9 10 11 12
		where 1 to 12 are the elements of the matrix.
3. Private data member: double *mp[]; unsigned int rows, cols.
4. Write a main function to use the all functions in the above class.
*/ 
