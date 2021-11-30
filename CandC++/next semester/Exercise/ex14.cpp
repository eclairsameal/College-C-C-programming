//檔名:ex14.c
//編譯器:Dev-c++
//日期:2011/5/28 
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

typedef struct {//點座標 
  double x, y;
} Point;

class Line {
private:
  double a, b, c;
public:
  Line(double ai, double bi, double ci){
  setLine(ai, bi, ci);
}
void setLine(double ai = 0, double bi = 0, double ci = 0){
  a = ai;
  b = bi;
  c = ci;
}
  double getA(){return a;}
  double getB(){return b;}
  double getC(){return c;}
  
  string str(){
	stringstream line;	
    line << a << "x" << " + " << b << "y" << " = " << c; 
    return line.str();
  }//印出方程式 
  Point node(Line l1, Line l2){//求兩直線交點 
    Point p;
    p.y = (l1.a * l2.c - l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b);
    p.x = (l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b);
    return p;
  }
  double distance(Point p1, Point p2) {//點到點之間的距離函式
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));//回傳距離
  }
  double triangle_area(Point pa, Point pb, Point pc) {//三角形面積函式
    double s;
    s = (distance(pa, pb) + distance(pb, pc) + distance(pa, pc))/2;
    return sqrt(s * (s -distance(pa, pb)) * (s - distance(pb, pc)) * (s - distance(pa, pc)));//海龍公式
  }
  void result(Line l1, Line l2, Line l3){
    Point pa = l1.node(l1, l2) , pb = l1.node(l2, l3), pc = l1.node(l1, l3);
    cout << "The area formed by these three lines is " << l3.triangle_area(pa, pb, pc) << "\n";
  }
};

int main(){
  double a1, a2, a3, b1, b2, b3, c1, c2, c3;
  Point pa, pb, pc;
  cout << "nter the coefficients of the first line ax + by = c:";
  cin >> a1 >> b1 >> c1;
  cout << "Enter the coefficients of the second line ax + by = c:";
  cin >> a2 >> b2 >> c2;
  cout << "Enter the coefficients of the third line ax + by = c:";
  cin >> a3 >> b3 >> c3;
  Line l1(a1, b1, c1), l2(a2, b2, c2), l3(a3, b3, c3); 
  cout << "Three lines are " << l1.str() << ", " << l2.str() << " and " << l3.str() << "\n"; 
  l1.result(l1, l2, l3);
  system("pause");
}
/*
Create a class called Line to represent ax + by = c.
1. (4 points) Create the constructors, accessors, and mutators.
2. (3 points) Create a function to print the line.
3. (5 points) Create a function to return area of a triangle
formed by three lines. 
4. (2 points) Create the main function to use the class.

A possible run may look like:

Enter the coefficients of the first line ax + by = c: 4 3 12
Enter the coefficients of the second line ax + by = c: 1 0 0
Enter the coefficients of the third line ax + by = c: 4 -3 12
Three lines are 4x + 3y = 12, x = 0, and 4x - 3y = 12.
The area formed by these three lines is 12.00.

Hint:

#include <iostream>
using namespace std;

class Line {
private:
double a, b, c;
};
*/
