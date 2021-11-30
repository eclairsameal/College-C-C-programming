//檔名:hw5-2.cpp
//編輯器:Dev-C++
//日期:2012/5/25
#include<iostream>
#include<ctime>
#include <iomanip>
using namespace std;

class game{//建構game類別 
private:
  int points;  		
public:
  game(int points_x){
    setgame(points_x);
  }//建構子 
  void setgame(int points_x = 0){
    points = points_x;
  }//變異子 
  int getPoints(){
    return points;
  }//存取子 
  int winning_number(){
    return (rand() % 12) + 1; 
  }//起始亂數 
  int odd(int number){
    if(number % 2 == 1)return points;
    else return points-(2*points);
  }//奇數 
  int even(int number){
    if(number % 2 == 0)return points;
    else return points-(2*points);
  }//偶數 
  int low(int number){
  	int i;	 
    for(i = 1; i <= 4; i++){
	  if(number == i)return points * 2;
      else return points-(2*points);
	}
  }//low(1, 2, 3, 4) 
  int medium(int number){
  	int i;	 
    for(i = 5; i <= 8; i++){
	  if(number == i)return points * 2;
      else return points-(2*points);
	}
  }//medium(5, 6, 7, 8)
  int hing(int number){
  	int i;	 
    for(i = 9; i <= 12; i++){
	  if(number == i)return points * 2;
      else return points-(2*points);
	}//hing(9, 10, 11, 12)
  }
  int option_number(int number, int n){
	if(number == n)return points * 12;
    else return points-(2*points);     
  }//玩家選擇的數 
};

void game_board(){ 
  int i;
  cout << "Low "<< setw(7);
  for(i = 1; i <= 12; i++){
	cout << i << setw(4); 
    if(i == 4) cout << "\n" << "Medium " << setw(4);
    if(i == 8) cout << "\n" << "High " << setw(6);
  }
  cout << "\n";
}//列印

void winning_rate(){
  cout << "Choice           "  << "Risk:Winning\n";
  cout << "Odd|Even " << setw(12) << "1:1\n";
  cout << "Low|Medium|High " << setw(5) << "1:2\n";
  cout << "Number " << setw(15) << "1:12\n";
}//列印Choice	Risk:Winning

int main(){
  char option, go;//選擇 
  int risk, total = 0, guesses = 0, n;//賭金 總和 幾次	
  srand(time(NULL));
  game_board();
  cout << "===========================================================\n";
  winning_rate();
  
  do {
	cout << "===========================================================\n";
    cout << "Guesses Choices:";
    cout << "O-Odd E-Even L-Low M-Medium H-High N-Number\n";
    cout << "===========================================================\n";
    cout << "Enter your choice:";
    cin >> option;
    cout << "Point at risk:";
    cin >> risk;
    game g(risk);
    switch(option){
      case'O':{
	    int number = g.winning_number();
	    cout << "The winning number is " << number << "\n";
	    if(g.odd(number) < 0)cout << "You lost " << risk << " points.\n";
	    else cout << "You won " << risk << " points.\n";
        total+=g.odd(number);
        cout << total << "\n";
        guesses++;
        break;
	  }  
      case'E':{
	    int number = g.winning_number();
	    cout << "The winning number is " << number << "\n";
	    if(g.even(number) < 0)cout << "You lost " << risk << " points.\n";
	    else cout << "You won " << risk << " points.\n";
        total+=g.even(number);
        cout << total << "\n";
        guesses++;
        break;
	  }
	case'L':{
	  int number = g.winning_number();
	  cout << "The winning number is " << number << "\n";
	  if(g.low(number) < 0)cout << "You lost " << g.low(number) << " points.\n";
	  else cout << "You won " << risk << " points.\n";
      total+=g.low(number);
      guesses++;
      break;
	}
	case'M':{
	  int number = g.winning_number();
	  cout << "The winning number is " << number << "\n";
	  if(g.medium(number) < 0)cout << "You lost " << g.medium(number) << " points.\n";
	  else cout << "You won " << risk << " points.\n";
      total+=g.medium(number);
      guesses++;
      break;	
	}
	case'H':{
	  int number = g.winning_number();
	  cout << "The winning number is " << number << "\n";
	  if(g.hing(number) < 0)cout << "You lost " << g.hing(number) << " points.\n";
	  else cout << "You won " << risk << " points.\n";
      total+=g.hing(number);
      guesses++;
      break;	
	}
	case'N':{
	  int number = g.winning_number();
	  cout << "Enter your number:";
	  cin >> n;
	  cout << "The winning number is " << number << "\n";
	  if(g.option_number(number, n) < 0)cout << "You lost " << g.option_number(number, n) << " points.\n";
	  else cout << "You won " << risk << " points.\n";
      total+=g.option_number(number, n);
	  guesses++;	
	  break;
	}
  
  }
    cout << "Continue (Y/N)? ";
    cin >> go;
  } while (go == 'Y' || go == 'y');	
    cout << "Total number of guesses:" << guesses << "\n";
    cout << "Your current point:" << total << "\n";
  system("pause");
}
/*
Write a class that simulates a guessing game. The class may look like:
class game {
  private:
    int points;
  public:
    game() {};
    play() {};
}
1. Each time you choose among 6 possible guesses. The correct guess is based on the following game board which divides the numbers into rows and columns as shown below.
Low	1	2	3	4
Medium	5	6	7	8
High	9	10	11	12

The following table shows your choice and risk-winning rate:
Choice	Risk:Winning
Odd|Even	1:1
Low|Medium|High	1:2
Number	1:12

For example, you guess a low number and your points at risk are 20. If you guess right, you'll get 20 points.
2. The class will generate a random number between 1 and 12.
3. Each correct guess will be rewarded with points based on how many of your current points you risked.
4. The player can choose to continue to play.
5. If the player quit the game, print the winning or loosing points of the player.
#include <iostream>
using namespace std;
main() {
  char option, go;
  do {
    cout << "=======================================================\n";
    cout << "Guesses Choice:\n";
    cout << "O-Odd E-Even L-Low M-Medium H-High N-Number\n";
    cout << "=======================================================\n";
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
    }
    cout << "Continue (Y/N)? ";
    cin >> go;
  } while (go == 'Y' || go == 'y');
}
A possible run could look like as follows:
==========================================================
Guesses Choices: 
O-Odd E-Even L-Low M-Medium H-High N-Number
==========================================================
Enter your choice: E
Point at risk: 20
The winning number is 11.
You lost 20 points. 
Continue (Y/N)? Y
==========================================================
Guesses Choices: 
O-Odd E-Even L-Low M-Medium H-High N-Number
==========================================================
Enter your choice: H
Point at risk: 10
The winning number is 4.
You lost 10 points. 
Continue (Y/N)? Y
==========================================================
Guesses Choices: 
O-Odd E-Even L-Low M-Medium H-High N-Number
==========================================================
Enter your choice: N
Enter your number: 8
Point at risk: 5
The winning number is 8.
You won 60 points. 
Continue (Y/N)? N
==========================================================
Total number of guesses: 3
Your current point: 30
*/ 
