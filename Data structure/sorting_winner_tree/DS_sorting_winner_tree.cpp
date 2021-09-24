///////////////////////////////////////////////////////////////////////////////
// �{��: Homework chap05 - Winner Tree Sorting
// ����: array(class) 
// ���: 2013/3/11                                  
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Wintree{ // �ŧi Wintree class 
  public:
  	Wintree(fstream &filei){ 	
  	  int n; // Player
  	  char buffer[100];
      filei >> n;
      filei.getline(buffer,sizeof(buffer));  // �촫�� 
      filei.getline(buffer,sizeof(buffer)); // ��player����(�@��) 
      setPlayer(n);
      setNode_number(n);
      setSorted_array(n);      
      setArray_tree(getNode_number(), buffer);  
  	}  // �غc�l(Wintree) 
    void setPlayer(int in){player = in;} // set Player ���� 
	void setNode_number(int n){ // �ǤJ n(player) 
      int h = 0, in = 1; // h = height 
      while(n != 0){
        n = n/2;
        h++;
      } // �p��𰪫� 
      height = h;
      for(int i = 0; i < h; i++) in*=2; 
      node_number = in - 1;
    } // set Node_number ����(�p���@���h�ָ`�I), �]�p�� height ���� 
  	void setArray_tree(int n, char buffer[]){// (�`�@���h�ָ`�I, Ū��Player�r��) 
      char *pch; // �r�����ХΨӭp�Q���Ϊ��� 
      int a = getNode_number() - getPlayer(); // �q�ĴX�Ӷ}�l���� 
      array_tree = new int[n]; // �ʺA�_�l�}�C 
      for(int i = 0; i < n; i++) array_tree[i] = 0; // �N array_tree �k�s 
      pch = strtok(buffer, " ");
  	  while(pch != NULL){
	    array_tree[a] = atoi(pch); // �N�r���ন��� 
	    pch = strtok(NULL," :");
	    a++;
	  } // ���Φr��æs�J array_tree 
	} // set Array_tree
	void setSorted_array(int n){
      sorted_array = new int[n]; // �ʺA�_�l�}�C
      for(int i = 0; i < n; i++) sorted_array[i] = 0; // �N sorted_array �k�s
    } // �_�l sorted_array	
	int min(int a, int b){
      if(a>b)return b;
      else return a;
    }  // �P�_�ǤJ����ƽָ��p �j�Ǹ��p���� 	
	void instar(){
      int n;
      for(int i = getNode_number() - 1; i >= 0; i = i -2){ // getNode_number() = 31 
        n = min(array_tree[i], array_tree[i-1]); // �P�_���Ӥl�`�I���p      
        if(0!=array_tree[(i/2)-1]){ // �p�G���`�I�w�g����(0) 
          array_tree[(i/2)-1] = min(array_tree[(i/2)-1], n);                     
        } // �N n ����`�I���ȥ�� min 
        else array_tree[(i/2)-1] = n; // �p�G���`�I�S���� �s��       
      }      
    } // ��l������    
    void Retrieve(int n){ // n = �ƧǪ���m 
      int a = getNode_number() - getPlayer(), find = 0, b;
      // Player�barray�����Ĥ@�Ӧ�m, �O�_���Winner����m, �Ȧsmin��  
      sorted_array[n] = array_tree[0];// �NWinner���Ȧs��sorted_array 
      array_tree[0] = 10; // �NWinner��10���N 
      while(find != 1){
        if(array_tree[a] == sorted_array[n]){ // ��Winner�_�쪺��m
          array_tree[a] = 10;        
          if(a%2 != 0){  // �p�GWinner�_�쪺��m�O�_��   
            for(int i = a; i>0; i = (i-1)/2)
              array_tree[i] = 10;
            }
          if(a%2 == 0){ // �p�GWinner�_�쪺��m�O���� 
            for(int i = a; i>0; i = (i/2)-1)
              array_tree[i] = 10;
          }  
          find = 1;
        }        
        else a++;
      } //  while, ���Winner����m�N���X 
      for(int i = getNode_number() - 1; i >= 0; i = i -2){
        b = min(array_tree[i], array_tree[i-1]); // �P�_���Ӥl�`�I���p   
        array_tree[(i/2)-1] = b; // �s�� 
      } 
    } // �Ƨ�    
	int getPlayer(){return player;} // �� player ����
  	int getNode_number(){return node_number;} // �� node_number ���� 
    int getHeight(){return height;} // �� height ���� 
    void printf_tree(fstream &fileo){
      for(int i =0; i < getNode_number(); i++){
        if(array_tree[i] == 10){
        cout << "#"; 
        fileo << "#";
        }
        else {
          cout << array_tree[i];
          fileo << array_tree[i];
        }
        cout << " ";
        fileo << " ";
      }
      cout << endl;
      fileo << endl;
    } // �L�Xarray_tree����
    void printf_sorted(fstream &fileo){
      cout << "Sorted array: ";
      fileo << "Sorted array: ";
      for(int i =0; i < getPlayer(); i++){
        if(sorted_array[i]==0){
          cout << "-";
          fileo << "-";
        } 
        else {
          cout << sorted_array[i];
          fileo << sorted_array[i];
        }
        cout << " ";
        fileo << " ";
      }
      cout << endl;
      fileo << endl;
    } // �L�Xsorted_array����   
  private:
  	int player; // player
  	int node_number; // �}�C���Ӽ� 
  	int height; // �𪺰���(�bsetNode_number�����) 
	int *array_tree;
	int *sorted_array; // �Ƨǫ᪺�� 
};
// Wintree class �ŧi���� 
void funtion(fstream &filei, fstream &fileo){ // funtion  
  class Wintree w(filei); // �ŧi�@�ӦW�� w �� Wintree class
  cout << "Before tree initialization:\n"; 
  fileo << "Before tree initialization:\n";
  w.printf_tree(fileo); // �u�� player �����A 
  cout << "After tree initialization:\n";
  fileo << "After tree initialization:\n";
  w.instar(); // �_�l�� 
  w.printf_tree(fileo);
  for(int i = 0; i < w.getPlayer(); i++){ // �Ƨ� 
    w.Retrieve(i);
    cout << "Retrieve " << i+1 << " number(s):\n";
    fileo << "Retrieve " << i+1 << " number(s):\n";
    cout << "tree: ";    
    fileo << "tree: ";
    w.printf_tree(fileo); 
    w.printf_sorted(fileo);      
  }
}
///////////////////////////////////////////////////////////////////////////////
int main(){
  fstream filei, fileo;   
  filei.open("input.txt", ios::in); // Ūinput.txt
  fileo.open("output.txt", ios::out); // �goutput.txt 
  funtion(filei, fileo); // �I�sfuntion
  system("pause");
  return 0;
}
