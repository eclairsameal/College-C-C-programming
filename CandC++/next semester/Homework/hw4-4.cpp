//檔名:hw4-4.cpp
//編輯器:Dev-C++
//日期:2012/5/6
#include <iostream>
#include <cmath>
using namespace std;
//建立Function類比
class Function{
  private:
    double x, y, z, k;
  public:
    Function(double ia = 0, double ib = 0, double ic = 0, double ik = 0){
	  x = ia;
	  y = ib;
	  z = ic;
	  k = ik;
	}//建構子
	void setFunction(double ia = 0, double ib = 0, double ic = 0, double ik = 0){
	  x = ia;
	  y = ib;
	  z = ic;
	  k = ik;
	}//變異子 	
    double getA() { return x; }
    double getB() { return y; }
    double getC() { return z; }
    double getK() { return k; }
    //存取子 
    double printf_function1(){
	  cout << "The function is " << x << "x^2" << " + " 
	    << y << "x" << " + " << z << "\n";	       
	}//印出方程式 
	double value(Function f){
	  return (f.x * f.k * f.k) + (f.y * f.k) + f.z;	
	}//x帶入方程式後計算的結果 
    double printf_value(Function f){
      cout << "The function value is " << f.value(f) << "\n";  
    }	
	void x_value(Function f){
	   double d;
	   d = (f.y * f.y) - (4 * f.x * f.z);
       if( d > 0 ) {
         cout << "x = " << (-1 * f.y - sqrt(d))/(2 * f.x) <<", " 
		 << "x = "<<(-1 * f.y + sqrt(d))/(2 * f.x)<<endl;
       }
       else if ( d == 0 ) {
         cout << "x = " << (-1 * f.y + sqrt(d))/(2 * f.x) << endl;
       }
      else if ( d < 0 ) {
        cout<<"無實數解"<<endl;
      } 
	}//計算方程式的解 
    double integral(Function f, double fe, double fs, double n){
      double h, sum = 0.0, y, x;
      h = (fe - fs) / n;
      for(x = fs; x < fe; x+=h){
        y = h * (f.x * x * x + f.y * x + f.z + f.x * (x + h) * (x + h) + f.y * (x + h) + f.z) / 2;
        if(y < 0) y =- y;
        sum += y;
      }
   	  return sum; 
    }//積分	
};

int main(){
  double a, b, c, k, s, e, n;
  
  cout << "Enter a, b, c:";
  cin >> a >> b >> c;
  Function f1(a, b, c, k);
  f1.printf_function1();
  cout << "Enter a, b, c, and x:";
  cin >> a >> b >> c >> k;
  Function f2(a, b, c, k);
  f2. printf_value(f2);
  cout << "Enter a, b, and c:";
  cin >> a >> b >> c;
  Function f3(a, b, c, k);
  f3.x_value(f3);
  cout << "Enter a, b, c, s, e, n:";
  cin >> a >> b >> c >> s >> e >> n;
  f3.setFunction(a, b, c, k);
  cout << "The integral is "<< f3.integral(f3, e, s, n);
  system("pause");
}
/*
Design and implement a class for a function f(x) = ax2 + bx + c.
1. Write a constructor that passes a, b, and c to initialize the function.
2. Write a method that prints the function in the form ax^2 + bx + c.
3. Write a method that passes a, b, c, and x and returns the function value.
4. Write a method that passes a, b, and c and shows x's value when f(x) = 0.
5. Write a method that passes a, b, c, s, e, and n and returns the integral value of the function from s to e where n is the number of divisions between s and e. The integral of the function f(x) from s to e be can be approximated by the formula: Δx[f(x1) + f(x2) + · · · + f(xn)] where x0 = s, xn = e, Δx = (s - e)/n and xi = 1/2(xi - 1 + xi) is the midpoint of [xi - 1, xi].
60 Write a main method to use the above class.
A possible run may look like:

Enter a, b, c: 1 2 3
The function is 1.0000x^2 + 2.0000x + 3.0000
Enter a, b, c, and x: 2 3 4 4
The function value is 48.0000.
Enter a, b, and c: 1 -3 2
x = 1.0000, x = 2.0000
Enter a, b, c, s, e, n: 1 1 0 0 1 1000
The integral is 0.8333333333.
*/ 
