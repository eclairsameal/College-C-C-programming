//檔名:ex11.cpp
//編輯器:Dev-C++
//日期:2012/5/5
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
//建立Board類比 
class Board {
  private:
    int n, **a;
  public:
    Board(int in = 0) {
	  int i;
	  n = in;
	  a = new int *[n];
	  for (int i = 0; i < n; i++) a[i] = new int[n]; 
	}//建構子
    void setBoard(int in = 0) {
	  n = in;
	  a = new int *[n];
	  for (int i = 0; i < n; i++) a[i] = new int[n];
	}//變異子		
	int getN() {return n;}
    void variable() {//產生亂數的二維陣列 
	  int i, j, count, *p;
	  srand(time(NULL));
	  
      for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++){ 
		  a[i][j] = rand() % (n * n) + 1;
          for(count = 0, p = &a[0][0]; p < &a[i][j]; p++)if(*p == a[i][j]) count++;
          if(count > 0)if(j == n){i--; break;}
          else j--;//使數字不重複   
		}
	  }
	}
	void printf(){//列印二維陣列 
	  int i, j;
	  for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << setw(4) << a[i][j] << " ";
        cout << "\n";
      }	
	}

};
int main(){
  int n;
  
  cout << "Enter n:";
  cin >> n;
  Board b(n);
  b.variable();	
  b.printf();  
  system("pause");
}
/*
Create a class called Board to represent a board of numbers.
1. (4 points) Create the constructors which randomly filled a board of n by n
   with numbers from 1 to n * n.
2. (4 points) Create the accessors and mutators.
2. (2 points) Create a function to print the the board.
3. (2 points) Create the main function to use the class.

A possible run may look like:

Enter n: 3
The randomly generated MatchPair board is shown as below:
2 1 6
4 7 5
9 8 3
Enter n: 5
 10 20  8 17 12
  6 19  3  7  5
  1  4 13 11 22
 15  9 21  2 24
 16 14 18 12 19

Hint:

1.

class Board {
  private:
    int a[10][10], n;
};


/*
 * Randomly generate 1 to 49
 */
/*main() {

  int lucky[6] = {0}, i, j;

  srand(time(0));
  for (i = 0; i < 6; i++) {
    lucky[i] = rand() % 49 + 1;
    for (j = 0; j < i; j++)
      if (lucky[i] == lucky[j]) {
        j = -1;
        lucky[i] = rand() % 49 + 1;
      }
    printf("%d ", lucky[i]);
  }
}
*/ 
 
