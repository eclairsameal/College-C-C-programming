//檔名:hw4-2.cpp
//編輯器:Dev-C++
//日期:2012/5/4
#include <iostream>
#include <cmath> 
using namespace std;

typedef struct{
  double x, y;
}Point;
//建立Circle類比 
class Circle{
  private:
    Point p;
	double r;		
  public:
    Circle (Point ip, double ir){
	  p = ip;
	  r = ir;
	}//建構子
	void setCircle (Point ip, double ir){
	  p = ip;
	  r = ir;
	}//變異子 
    Point getP() {return p;}
    double getR() {return r;}
    //列印輸入的點跟半徑 
    void printf_point(){
      cout << "The circle has the center point at (" << 
	    p.x << "," << p.y << ") and the radius " << r << "\n"; 
    }
    //計算圓的面積
    double area_circle(Circle c){ 
      return 3.14159 * c.r * c.r;  
    }
    //圓內最大矩形面積 
    double inner_square(Circle c){ 
      return sqrt((c.r * c.r) + (c.r * c.r)) * sqrt((c.r * c.r) + (c.r * c.r));
    }
	//圓的周長 
	double circumference(Circle c){
	  return 2 * 3.14159 * c.r;	
	} 
    //回傳兩點距離 
    double distance(Point p1, Point p2){
      return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); 
    }
    //判斷輸入的點是否在圓中
    bool point_circle(Circle c, Point p){
      double d = distance(c.p, p);
      if(d > c.r)return true;//圓外 
      else return false;//圓內 
    }
 
};

void result(Circle c, Point p){  
  cout << "The area of the circle is " << c.area_circle(c) << "\n";
  cout << "The circumference of the circle is " << c.inner_square(c) << "\n";
  cout << "The area of the maximum inner square is " << c.circumference(c) << "\n";
  if(c.point_circle(c, p))cout << "The point is outside the rectangle." << "\n";
  else cout << "The point is inside the circle." << "\n";    
}

int main(){
  Point cp, p;
  double r;
  
  cout << "Enter the central point (x, y) and the radius of the circle: ";
  cin >> cp.x >> cp.y >> r;
  Circle c(cp, r);
  cout << "Enter the point (x, y):";
  cin >> p.x >> p.y;
  c.printf_point();
  result(c, p); 
  system("pause");
}
/*
typedef struct {
  double x, y;
} Point;
1.Constructor summary: 
    Circle(Point p, double r ): Construct a circle with the center at p and the radius r.
2.Member function summary:
	1. Point getCenter(): Return the centeral point of the circle.
	2. double getRadius(): Return the radius of the circle.
	3. void setCircle(Point p, double r): Set a circle with the radius r.
	4. double getArea(): Return the area of the circle.
	5. double getSquareArea(): Return the area of the maximum square inside the circle.
	6. double getCircumference(): Return the circumference of the circle.
	7. bool isInside(Point p): Return true if the point p is inside the circle and false if the point p is outside of the circle.
3.Private data members: p and r.
4.Write a main function that presents a menu for the above functions of the circle.

A possible session may look like as follows:

Enter the central point (x, y) and the radius of the circle: 2 2 5
Enter the point (x, y): 10 -8
The circle has the center point at (2.00, 2.00) and the radius 5.00.
The area of the circle is 78.53982.
The circumference of the circle is 31.41593.
The area of the maximum inner square is 50.
The point (10, -8) is outside the rectangle.

Enter the central point (x, y) and the radius of the circle: 3 3 4
Enter the point (x, y): 4 5
The circle has been changed with the center point at (3.00, 3.00) and the radius 4.00.
The area of the circle is 50.26548.
The circumference of the circle is 25.13274.
The area of the maximum inner square is 32.
The point (4, 5) is inside the circle.
*/
