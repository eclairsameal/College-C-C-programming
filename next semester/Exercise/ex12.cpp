//檔名:ex12.cpp
//編輯器:Dev-C++
//日期:2012/5/10
#include<iostream>
using namespace std;
//建立Circle類別 
class Circle {
private:
  double a, b, r;
public:
  Circle(double ia, double ib, double ir){
    setCircle(ia, ib, ir);
  }//建構子
  void setCircle(double ia, double ib, double ir){
    a = ia;
    b = ib;
    r = ir;
  }//變異子
  double getA(){return a;}
  double getB(){return b;}
  double getR(){return r;}
  void printf_line(){
  cout << "(" << "x" << " - " << a << ")" << "^2" << " + " 
    << "(" << "y" << " - " << b << ")" << "^2"<< " = " << r * 2 << "\n";
  }//列印方程式
  double area(){
    return r * 2 * 3.14159265;
  }//計算圓積
};

int main(){
  double a, b, r;
  cout << "Enter the circle equation (x - a)^2 + (y - b)^2 = r^2:";
  cin >> a >> b >> r;
  Circle c(a, b, r);
  c.printf_line();
  cout << "The area is " << c.area();
system("pause");
}
/*
Create a class for a equation for a circle which has the format (x - a)^2 + (y - b)^2 = r^2
where (a, b) is the center of the circle.
1. (6 points) Create the constructors, accessors, and mutators.
2. (2 points) Create a function to print the line equation in the format of
   (x - a)^2 + (y - b)^2 = r^2.
3. (2 points) Create a function that returns the area of the circle.
4. (2 points) Create the main function to use the class.

A possible run may look like:

Enter the circle equation (x - a)^2 + (y - b)^2 = r^2: 0 0 2
The circle is x^2 + y^2 = 4.0000
The area is 12.56637061436.

Hint:
class Circle {
  private:
    double a, b, r;
};
*/
