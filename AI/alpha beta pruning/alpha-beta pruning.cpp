///////////////////////////////////////////////////////////////////////////////
// �ت�: ��X�C�Ӹ`�I�� alpha beta �ȡC�̫�C�L�X A,B,C,D�|�Ӹ`�I�� minmax ��
// ����: alpha-beta pruning
// ���: 2013/5/18                                 
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define MAX 100 
#define MIN -100  
using namespace std;

class Node{
  public:
    int value; // �`�I���� 
    int pa; // �l�`�I�`�� 
    int a; // min
    int b; // max
};

class Alpha_beta{
  public:
    Alpha_beta(fstream &filei, int in, int ih, int leaf){
	  setNode_nu(in);
	  setHeight(ih);
	  newNode(leaf);
      setNode(filei);
    }
    void setNode_nu(int in){node_nu = in;}
    void setHeight(int ih){height = ih;}
    void newNode(int leaf){
	  node_array = new Node[node_nu];	  
	  for(int i = 0; i < node_nu; i++){
	    if(i < node_nu - leaf){node_array[i].a = MIN; node_array[i].b = MAX;}
	    else{node_array[i].a = 0; node_array[i].b = 0;}		
	  }
	}
	void setNode(fstream &filei){
	  char buffer[100], *pch;
	  int a = 0;
	  filei.getline(buffer, sizeof(buffer)); 
      filei.getline(buffer, sizeof(buffer));
      pch = strtok(buffer, " ");
      while(pch!=NULL){
        node_array[a++].value = atoi(pch);
        pch = strtok(NULL," ");              
      }
      a = 0;
      filei.getline(buffer, sizeof(buffer));
	  pch = strtok(buffer, " ");
      while(pch!=NULL){
        node_array[a++].pa = atoi(pch);
        pch = strtok(NULL," ");              
      }	  			
	}
	int alphabeta(int node, int depth, bool maximizingPlayer){
	  int child = 0;
	  bool f = false;
	  if(depth == 0 || node_array[node].pa == 0){ 
		return node_array[node].value;
	  }
	  if (maximizingPlayer){
	    for(int i = 1; i <= node_array[node].pa ;i++){	  
		  child = i;
		  for(int j = 0; j < node; j++){child += node_array[j].pa;}
		  //cout << "max: " << child << ", " << node << "\n";
		  node_array[node].a = max(node_array[node].a, alphabeta(child, depth - 1, false));		  
		  if(node_array[0].b <= node_array[node].a){ f = true; break;}
		} 
		node_array[node].value = node_array[node].a;
		if(f == false)node_array[node].b = node_array[node].a;
		return node_array[node].a; 	
	  }
	  else{
	    for(int i = 1; i <= node_array[node].pa ;i++){
		  child = i;
		  for(int j = 0; j < node; j++){child += node_array[j].pa;}
		  //cout << "min: "<< child << ", " << node << "\n";		  
		  node_array[node].b = min(node_array[node].b, alphabeta(child, depth - 1, true));
		  if(node_array[0].a >= node_array[node].b){ f = true; break;}
		}
		node_array[node].value = node_array[node].b;
		if(f == false) node_array[node].a = node_array[node].b;
		return node_array[node].b; 	  
	  }
	}
	void algorithm(int leaf){
	  int point = 0;
	  char c = 'A';
      node_array[point].value = alphabeta(point, height, false);	
	  cout << "minmax: ";
	  for(int i = 0; i < node_nu-leaf; i++){c+=i; cout << c << "=" << node_array[i].value << "  "; }cout << "\n";
	  cout << "alpha beta: ";
	  c = 'A';
	  for(int i = 0; i < node_nu-leaf; i++){
		c+=i; 
		cout << c << "(" ;
		if(node_array[i].a == MIN){cout << "-��" << ", "; }
		else{cout << node_array[i].a << ", ";}
		if(node_array[i].b == MAX){cout << "��" << ") "; }
		else{cout << node_array[i].b << ") ";}		 
	  } cout << "\n";	 	
	}	
  private:
	Node *node_array;
    int node_nu;
	int height;			
};

int main(){
  fstream filei;
  int n, h, leaf;	
  filei.open("input.txt", ios::in);
  filei >> n;
  filei >> h;
  filei >> leaf;
  class Alpha_beta a(filei, n, h, leaf);
  a.algorithm(leaf); 	
  system("pause");
  return 0;
}
/*
function alphabeta(node, depth, �\, �])
 (* �] represents previous player best choice - doesn't want it if �\ would worsen it *)
 if depth = 0 or node is a terminal node
 return the heuristic value of node
 for each child of node
 �\ := max(�\, -alphabeta(child, depth-1, -�], -�\))
 (* use symmetry, -�] becomes subsequently pruned �\ *)
 if �]?�\
 break    (* Beta cut-off *)
 return �\
*/
