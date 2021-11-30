//�ɦW:ex12.cpp
//�s�边:Dev-C++
//���:2012/5/10
#include<iostream>
using namespace std;
//�إ�Circle���O 
class Circle {
private:
  double a, b, r;
public:
  Circle(double ia, double ib, double ir){
    setCircle(ia, ib, ir);
  }//�غc�l
  void setCircle(double ia, double ib, double ir){
    a = ia;
    b = ib;
    r = ir;
  }//�ܲ��l
  double getA(){return a;}
  double getB(){return b;}
  double getR(){return r;}
  void printf_line(){
  cout << "(" << "x" << " - " << a << ")" << "^2" << " + " 
    << "(" << "y" << " - " << b << ")" << "^2"<< " = " << r * 2 << "\n";
  }//�C�L��{��
  double area(){
    return r * 2 * 3.14159265;
  }//�p���n
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
