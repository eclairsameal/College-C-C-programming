//�ɦW:ex9.cpp
//�s�边:Dev-C++
//���:2012/4/23 
#include<iostream>
using namespace std;

class Vector{//�إ�Vector���O 
  private://�p���ܼ� 
    double x, y, z;   
  public: //�@�� 	
    Vector(double a = 0, double b = 0, double c = 0) {
      x = a;
      y = b;
      z = c;
    }//�غc�l
    double getX() { return x; };
    double getY() { return y; };
    double getZ() { return z; };
    void setVector(double a = 0, double b = 0, double c = 0) {
      x = a;
      y = b;
      z = c;
    }//�ܲ��l	
	Vector addition(Vector p1, Vector p2){
	  Vector psum;
	  psum.x = p1.x + p2.x;
	  psum.y = p1.y + p2.y;
	  psum.z = p1.z + p2.z; 
	  return psum;
	}//�[�k
	Vector substraction(Vector p1, Vector p2){
	  Vector psum;
	  psum.x = p1.x - p2.x;
	  psum.y = p1.y - p2.y; 
	  psum.z = p1.z - p2.z;
	  return psum;	  
	}//��k
	double inner_product(Vector p1, Vector p2){
	  return p1.x *  p2.x + p1.y * p2.y + p1.z * p2.z;	  
	}//���k			
};

main(){
  double x1, y1, z1, x2, y2, z2;
  cout << "Enter two vectors a, b:";	
  cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;//��J�V�q
  
  Vector p1(x1, y1, z1), p2(x2, y2, z2), psum;
  
  psum = psum.addition(p1, p2);//�I�s�[�k�禡 
  cout << "(" << p1.getX() << " " << p1.getY()<< " " << p1.getZ()
    << ")" << " + " << "(" << p2.getX() << " " << p2.getY()<< " " 
	<< p2.getZ() << ")" << " = " << "(" << psum.getX() << " " << 
	psum.getY()<< " " << psum.getZ() << ")" << "\n";
	
  psum = psum.substraction(p1, p2);//�I�s��k�禡 
  cout << "(" << p1.getX() << " " << p1.getY()<< " " << p1.getZ()
    << ")" << " - " << "(" << p2.getX() << " " << p2.getY()<< " " 
	<< p2.getZ() << ")" << " = " << "(" << psum.getX() << " " << 
	psum.getY()<< " " << psum.getZ() << ")" << "\n";
	//���k
  cout << "(" << p1.getX() << " " << p1.getY()<< " " << p1.getZ()
    << ")" << " * " << "(" << p2.getX() << " " << p2.getY()<< " " 
	<< p2.getZ() << ")" << " = " << psum.inner_product(p1, p2) << "\n";
  
 
  system("pause");
}
/*
Consider the following class for a vector.

class Vector {
  private:
    double x, y, z;
};

Write constructor, mutators, and accessors for the vector class and member functions 
to return addition, substraction, and inner product of two vectors. A possible run may
look like:

Enter two vectors a, b: 1 2 3 4 5 6
(1, 2, 3) + (4, 5, 6) = (5, 7, 9)
(1, 2, 3) - (4, 5, 6) = (-3, -3, -3)
(1, 2, 3) * (4, 5, 6) = 32

Hint:

Vector add(Vector a, Vector b) {
  Vector c;
  return c;
}
*/ 
