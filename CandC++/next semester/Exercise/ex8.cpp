//檔名:ex8.cpp
//編輯器:Dev-C++
//日期:2012/4/15 
#include <iostream>
#include <string>
using namespace std;

class Basketballteam {  //建立Basketballteam類別 
  private://私有 
    string name, coach, membersnumber;//變數的宣告 
  public://共有   
    Basketballteam(string n = "", string c = "", string m = "") {
      name = n;
      coach = c;
      membersnumber = m;
    }
    string getName() { return name; };//讀取函式 
    string getCoach() { return coach; };//讀取函式
    string getMembersnumber() { return membersnumber; };//讀取函式
    void setBasketballteam(string n = "", string c = "", string m = "") {//設定Basketballteam函式 
      name = n;
      coach = c;
      membersnumber = m;
    }
};

main() {
  string name, coach, membersnumber;
  //輸入 
  cout << "Enter name: ";
  getline(cin, name);
  cout << "Enter coach: ";
  getline(cin, coach);
  cout << "Enter number of members: ";
  getline(cin, membersnumber);
  
  Basketballteam Team(name, coach, membersnumber);//建立物件 
  //列印結果 
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
