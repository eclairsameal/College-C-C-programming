//檔名:ex15.c
//編譯器:Dev-c++
//日期:2012/6/14 
#include <iostream>
#include <cmath>
using namespace std;
class Point{
  private:
    double x, y;
  public:
   Point(double _x = 0, double _y = 0){
     setPoint(_x, _y);
   }//建構子 
   void setPoint(double _x = 0, double _y = 0){
   x = _x;
   y = _y;
   }//變異子
   double getX(){return x;}
   double getY(){return y;}
   Point operator+(Point p){
     Point sum(x + p.x, y + p.y);
     return sum;  
   }//加法 
   Point operator-(Point p){
     Point sum(x - p.x, y - p.y);
     return sum;  
   }//減法 
   double operator|(Point p){         
     return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));  
   }//距離 
   void printf_point(){
     cout << "( " << x << ", " << y << " )" << "\n";   
   }
};

main(){
  double x1, x2, y1, y2;
  double sum = 0;
  
  cout << "Enter first point: ";
  cin >> x1 >> y1;
  cout << "Enter second point: ";
  cin >> x2 >> y2;
  Point p1(x1, y1), p2(x2, y2), p;
  p = p1 + p2;
  cout << "The sum of two points is ";
  p.printf_point();
  p = p1 - p2;
  cout << "The substraction of two points is ";
  p.printf_point();
  sum = p1 | p2;
  cout << "The distance of two points is " << sum << "\n"; 
  system("pause");
  return 0;
}
 /*
 Create a class for a point including constructors, mutators, and accesors,
 and the following functions:

 +(Point b) : this point is the result of adding two point (this and b).
 -(Point b) : this point is the result of substrating b from this.
 ||(Point b) : the distance from this to b.
 print() : print the point in the format of (x, y).
 Private data members: double x, y.
 The possible run may look like:

 Enter first point: 1 2
 Enter second point: 4 6
 The sum of two points is (5, 8).
 The substraction of two points is (-3, -4).
 The distance of two points is 5.000.


*/
