//檔名:ex15.c
//編譯器:Dev-c++
//日期:2011/5/31 
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class Table {
private:
  int **table, row, col, range;
public:
  Table(int _row = 0, int _col = 0, int _range = 0){
    setTable(_row, _col, _range);          
  }//建構子
  void setTable(int _row, int _col, int _range){
    row = _row;
    col = _col;
    range = _range;
    table = new int *[row];
    for (int i = 0; i < row; i++) table[i] = new int[col];
  }//變異子
  int getRow(){return row;}
  int getCol(){return col;}
  int getRange(){return range;}
  
  void rand_value(){
    srand(time(0));
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        table[i][j]= range - rand()%(2 * range + 1);
      }
    }
  }//產生亂數的二維陣列
  void printf_value(){
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        cout << setw(6) << table[i][j];
      }
      cout << "\n\n";
    }
  }//列印亂數的二維陣列
  void number(int a, int b){
    cout << "The value is " << table[a - 1][b - 1] << "\n";  
  }//找出輸入的值      
};

int main(){
  int row, col, range, a, b;
  cout << "Enter the size of the table and the value range:";
  cin >> row >> col >> range;
  cout << "The Number Table is:\n";
  Table t(row, col, range);
  t.rand_value();
  t.printf_value();  
  cout << "Enter the row number and column number:";
  cin >> a >> b;
  t.number(a, b);
  system("pause");
}
/*
   Create a class called Table that contains a table of numbers. 
   The class contains the following opearations:

   Constructor:

   Table(int m, int n, int r): create a table with n rows and
   m columns and randomly fill the element with the value between -r 
   and r.
  
   Destructor:
   ~Table(): release the memory taken by the table.

   Member functions:

   getValue(int i, int j): get the value of the element at ith row
   and jth column.
   print(): print this table.
 
   Private data member: int **table, row, col, range; 

   A possible session may look like:

   Enter the size of the table and the value range: 2 2 6
   1 -4
   -2 3
   Enter the row number and column number: 1 2
   The value is -4.

   Enter the size of the table and the value range: 3 7 40
   The Number Table is:

    8  22  -9 33 -18 17 32
   38 -27  12  8 -22 16  5
    3 -11  29 -31 19 25 14
   Enter the row number and column number: 3 4
   The value is -31.
*/
