//�ɦW:ex8.cpp
//�s�边:Dev-C++
//���:2012/4/15 
#include <iostream>
#include <string>
using namespace std;

class Basketballteam {  //�إ�Basketballteam���O 
  private://�p�� 
    string name, coach, membersnumber;//�ܼƪ��ŧi 
  public://�@��   
    Basketballteam(string n = "", string c = "", string m = "") {
      name = n;
      coach = c;
      membersnumber = m;
    }
    string getName() { return name; };//Ū���禡 
    string getCoach() { return coach; };//Ū���禡
    string getMembersnumber() { return membersnumber; };//Ū���禡
    void setBasketballteam(string n = "", string c = "", string m = "") {//�]�wBasketballteam�禡 
      name = n;
      coach = c;
      membersnumber = m;
    }
};

main() {
  string name, coach, membersnumber;
  //��J 
  cout << "Enter name: ";
  getline(cin, name);
  cout << "Enter coach: ";
  getline(cin, coach);
  cout << "Enter number of members: ";
  getline(cin, membersnumber);
  
  Basketballteam Team(name, coach, membersnumber);//�إߪ��� 
  //�C�L���G 
  cout << "Basketball team\n" << "Name:"<<Team.getName()<<"\n"
       << "Coach:"<<Team.getCoach()<<"\n"<<"number of members:"
	   << Team.getMembersnumber()<<"\n";
 
  system("pause");
}
/*
 Based on the last digital of your student number, create a class and the main
 function to use it. The class should include constructors, accessor, mutators,
 and at least 3 private data members.
 
 1. (0, 1) university
 2. (2, 3) name card
 3. (4, 5) travel agent
 4. (6, 7) basketball team
 5. (8, 9) music festival
 
Hint:

class Student {
  private:
    string no, name, major;
  public:
};

main() {
}
*/ 
