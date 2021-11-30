//檔名:ex13.cpp
//編輯器:Dev-C++
//日期:2012/5/19
#include <iostream>
#include <sstream>
using namespace std;
//建立Fraction類別 
class Fraction {
  private:
    int n, d;// n分子 d分母
  public:
    Fraction(int ni = 0, int di = 0){
	  setFraction(ni, di);
	}//建構子
    void setFraction(int ni = 0, int di = 0){
	  n = ni;
	  d = di;
	}//變異子
	int getN(){return n;}
	int getD(){return d;}
	Fraction operator+(Fraction f1){
	  Fraction f;
	    f.setFraction(((f1.n * d) + (n * f1.d))/f.gcd(((f1.n * d) + (n * f1.d)), (f1.d * d)), (f1.d * d)/f.gcd(((f1.n * d) + (n * f1.d)),(f1.d * d)));
	    return f;
	}//加法的多載 
	Fraction operator*(Fraction f1){
	  Fraction f;
	    f.setFraction((f1.n * n)/f.gcd((f1.n * n),(f1.d * d)), (f1.d * d)/f.gcd((f1.n * n),(f1.d * d)));
	    return f;
	}//乘法的多載 
	int gcd(int a, int b) {
      if (b == 0) return a;
      return gcd (b, a % b);
    }
	string str(){
	  stringstream fraction;
	  fraction << n << "/" << d;
	  return fraction.str();
	}//印出分數 
};
 // void printff(Fraction f){
 // int i = f.gcd(f.getN(), f.getD());
 // cout << f.getN()/i << "/" << f.getD()/i;  
  //}

int main(){
  int n1, d1, n2, d2;
  char op1, op2;
  
  cout << "Enter two fractions:";
  cin >> n1 >> op1 >> d1 >> n2 >> op2 >> d2;
  Fraction f1(n1, d1), f2(n2, d2), fadd, f;
  fadd = f1 + f2;
  cout << f1.str() << " + " << f2.str() << " = " << fadd.str() << "\n";
  f = f1 * f2;
  cout << f1.str() << " * " << f2.str() << " = " << f.str() << "\n";
  system("pause");
}
/*
o Put your student number and name and add necessary comments into the code
  you created. These are a part of grading in the assignment.
o Use ecampus (ecampus.chu.edu.tw) to submit all code including your
  document electronically. The submission ID is "Exercise 13".

(12 points)

Create a class for a fraction to represent n/d. Write fuctions to
overload + and *. The fractions should be in the reduced form.

A possible run may look like:

Enter two fractions: 3/4 2/3
3/4 + 2/3 = 17/12
3/4 * 2/3 = 1/2

Hint:
class Fraction {
  private:
    int n, d;
};



int GCD(int x,int y)
{
int i;//宣告整數R用來存放餘數 
//當A除以B有餘數時則持續作輾轉相除法
    while ( (i = x % y) != 0 )
    {//除完一次後，除數被除數互換
        x = y;
        y = i;
    }
return y;//回傳最大公因數y


int gcd(int a, int b) {
if (b == 0) return a;
return gcd (b, a % b);
}


}
*/
