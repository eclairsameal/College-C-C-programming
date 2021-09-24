///////////////////////////////////////////////////////////////////////////////
// 程式: Homework chap05 - Winner Tree Sorting
// 版本: array(class) 
// 日期: 2013/3/11                                  
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Wintree{ // 宣告 Wintree class 
  public:
  	Wintree(fstream &filei){ 	
  	  int n; // Player
  	  char buffer[100];
      filei >> n;
      filei.getline(buffer,sizeof(buffer));  // 抓換行 
      filei.getline(buffer,sizeof(buffer)); // 抓player的值(一行) 
      setPlayer(n);
      setNode_number(n);
      setSorted_array(n);      
      setArray_tree(getNode_number(), buffer);  
  	}  // 建構子(Wintree) 
    void setPlayer(int in){player = in;} // set Player 的值 
	void setNode_number(int n){ // 傳入 n(player) 
      int h = 0, in = 1; // h = height 
      while(n != 0){
        n = n/2;
        h++;
      } // 計算樹高度 
      height = h;
      for(int i = 0; i < h; i++) in*=2; 
      node_number = in - 1;
    } // set Node_number 的值(計算樹共有多少節點), 也計算 height 的值 
  	void setArray_tree(int n, char buffer[]){// (總共有多少節點, 讀的Player字串) 
      char *pch; // 字元指標用來計被切割的值 
      int a = getNode_number() - getPlayer(); // 從第幾個開始有值 
      array_tree = new int[n]; // 動態起始陣列 
      for(int i = 0; i < n; i++) array_tree[i] = 0; // 將 array_tree 歸零 
      pch = strtok(buffer, " ");
  	  while(pch != NULL){
	    array_tree[a] = atoi(pch); // 將字元轉成整數 
	    pch = strtok(NULL," :");
	    a++;
	  } // 切割字串並存入 array_tree 
	} // set Array_tree
	void setSorted_array(int n){
      sorted_array = new int[n]; // 動態起始陣列
      for(int i = 0; i < n; i++) sorted_array[i] = 0; // 將 sorted_array 歸零
    } // 起始 sorted_array	
	int min(int a, int b){
      if(a>b)return b;
      else return a;
    }  // 判斷傳入的兩數誰較小 迴傳較小的值 	
	void instar(){
      int n;
      for(int i = getNode_number() - 1; i >= 0; i = i -2){ // getNode_number() = 31 
        n = min(array_tree[i], array_tree[i-1]); // 判斷哪個子節點較小      
        if(0!=array_tree[(i/2)-1]){ // 如果父節點已經有值(0) 
          array_tree[(i/2)-1] = min(array_tree[(i/2)-1], n);                     
        } // 將 n 跟父節點的值丟到 min 
        else array_tree[(i/2)-1] = n; // 如果父節點沒有值 存值       
      }      
    } // 初始整顆樹    
    void Retrieve(int n){ // n = 排序的位置 
      int a = getNode_number() - getPlayer(), find = 0, b;
      // Player在array中的第一個位置, 是否找到Winner的位置, 暫存min值  
      sorted_array[n] = array_tree[0];// 將Winner的值存到sorted_array 
      array_tree[0] = 10; // 將Winner用10取代 
      while(find != 1){
        if(array_tree[a] == sorted_array[n]){ // 找Winner起初的位置
          array_tree[a] = 10;        
          if(a%2 != 0){  // 如果Winner起初的位置是奇數   
            for(int i = a; i>0; i = (i-1)/2)
              array_tree[i] = 10;
            }
          if(a%2 == 0){ // 如果Winner起初的位置是偶數 
            for(int i = a; i>0; i = (i/2)-1)
              array_tree[i] = 10;
          }  
          find = 1;
        }        
        else a++;
      } //  while, 找到Winner的位置就跳出 
      for(int i = getNode_number() - 1; i >= 0; i = i -2){
        b = min(array_tree[i], array_tree[i-1]); // 判斷哪個子節點較小   
        array_tree[(i/2)-1] = b; // 存值 
      } 
    } // 排序    
	int getPlayer(){return player;} // 取 player 的值
  	int getNode_number(){return node_number;} // 取 node_number 的值 
    int getHeight(){return height;} // 取 height 的值 
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
    } // 印出array_tree的值
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
    } // 印出sorted_array的值   
  private:
  	int player; // player
  	int node_number; // 陣列的個數 
  	int height; // 樹的高度(在setNode_number中找值) 
	int *array_tree;
	int *sorted_array; // 排序後的值 
};
// Wintree class 宣告結束 
void funtion(fstream &filei, fstream &fileo){ // funtion  
  class Wintree w(filei); // 宣告一個名為 w 的 Wintree class
  cout << "Before tree initialization:\n"; 
  fileo << "Before tree initialization:\n";
  w.printf_tree(fileo); // 只有 player 的狀態 
  cout << "After tree initialization:\n";
  fileo << "After tree initialization:\n";
  w.instar(); // 起始樹 
  w.printf_tree(fileo);
  for(int i = 0; i < w.getPlayer(); i++){ // 排序 
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
  filei.open("input.txt", ios::in); // 讀input.txt
  fileo.open("output.txt", ios::out); // 寫output.txt 
  funtion(filei, fileo); // 呼叫funtion
  system("pause");
  return 0;
}
