///////////////////////////////////////////////////////////////////////////////
// 程式: Shortest Path 
// 版本: Dijkstra Algorithm(class) 
// 日期: 2013/4/28                                  
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Dijkstra{ // 宣告 Dijkstra class 
  public:    
    Dijkstra(fstream &filei){
      int n = 0;
      char buffer[100];
      filei >> n;
      setVertices_number(n);
      filei.getline(buffer,sizeof(buffer)); // 抓一行
      newArray();
      setPD();
      setPath();
      setAdjacency_array(filei);
       
    } // 建構子(Dijkstra) 
    void setVertices_number(int n){vertices_number = n;}
    int getVertices_number(){return vertices_number;}
    
    void newArray(){      
      adjacency_array = new int*[getVertices_number()];
      for(int i = 0; i < getVertices_number(); i++)
        adjacency_array[i] = new int[getVertices_number()];
      for(int i = 0; i < getVertices_number(); i++){ 
        for(int j = 0; j < getVertices_number(); j++)
          adjacency_array[i][j] = 0;
      }
    }
    void setPD(){
      p = new int[getVertices_number()];
      d = new int[getVertices_number()];
      find_d = new bool[getVertices_number()];
      open_d = new bool[getVertices_number()];
      for(int i = 0; i < getVertices_number(); i++) p[i] = -1; 
      for(int i = 0; i < getVertices_number(); i++) d[i] = 1000;
      for(int i = 0; i < getVertices_number(); i++) find_d[i] = false;
      for(int i = 0; i < getVertices_number(); i++) open_d[i] = false;            
    } 
    void setPath(){
      path = new string[getVertices_number()];
      for(int i = 0; i < getVertices_number(); i++) path[i] = "";    
    }
    void setAdjacency_array(fstream &filei){
      char buffer[100], *pch;
      int count = 0, a = 0;
      while(!filei.eof() && count < getVertices_number()){       
        filei.getline(buffer,sizeof(buffer));
        a = 0;
        pch = strtok(buffer, " ");
        while(pch!=NULL){
          adjacency_array[count][a] = atoi(pch);
          a++; 
          pch = strtok(NULL," ");              
        }
        count++;
      }    
    }
    string inttostr(int &i) { //數字轉字串
      string s;
      stringstream ss(s);
      ss << i;
      return ss.str();
    } 
    void dijkstra(int source){
      int path_length = -1;
      int ns = 0;
       // 第一個值 
      d[source] = 0; // 設定起點的最短路徑長 
      p[source] = -1; // 設定此點的上一個位置(起點為自己) 
      find_d[source] = true; // 將起點加到最短路徑樹 
      open_d[source] = true;
      path_length = 0;
      ns = source + 1; 
      path[source] = inttostr(ns);
      Result(source, 0);
       // 找剩下的路徑 
      for(int i = 0; i < getVertices_number() - 1; i++){ // 最高跑的次數 
        int min = 999, a = -1;
        for(int j = 0; j < getVertices_number(); j++){        
           
          if(true!=find_d[j]){ // 檢查是否已找到路徑 
            if(0!=adjacency_array[source][j]){ // 點跟點之間有連接 
              if(true == open_d[j]){
                if(adjacency_array[source][j] + path_length < d[j]){
                  d[j] = adjacency_array[source][j] + path_length;
                  p[j] = source;
                  if(d[j] < min){min = d[j];a = j;}
                } 
                else{
                  if(d[j] < min){min = d[j];a = j;}
                } 
              }
              if(true != open_d[j]){
                d[j] = adjacency_array[source][j] + path_length;
                p[j] = source;
                open_d[j] = true;
                if(d[j] < min){min = d[j];a = j;}
              }
            }
            else{
              if(d[j] < min){min = d[j];a = j;}
            }
          }        
        }
        if (a == -1) break;
        path_length = min;
        source = a;       
        find_d[a] = true;  
        int as = a + 1;  
        path[a] = path[p[a]] + "-"+ inttostr(as);
        Result(a, path_length);
        if(min == 999)break;
      } 
    }
    // 資訊 
    void not_path(){
      bool b = false;
      for(int i = 0; i < getVertices_number(); i++){
        if(find_d[i]==false) b = true;
      }
      if(b == true){
        cout << "no path: ";
        for(int i = 0; i < getVertices_number(); i++){
          if(find_d[i]==false) cout << i + 1 << ", ";
        }
        cout << "\n";
      }
    }  
    void printfP(){
      for(int i = 0; i < getVertices_number(); i++){
        if(p[i] == -1)cout << "-" << "  ";
        else cout << p[i] + 1 << "  ";
      }
    }
    void printfD(){
      for(int i = 0; i < getVertices_number(); i++){
        if(d[i] == 1000)cout << "-" << "  ";
        else{
          if(d[i] > 9)cout << d[i] << " ";
          else cout << d[i] << "  ";
        } 
      }
    }
    void printfPath(int n){
      string str;
      str = path[n];
      str.resize(getVertices_number() * 2,' ');
      cout << str;
    }
    void Result(int n, int path_length){
      printfD();
      cout << "     ";
      printfP();
      cout << "      ";
      printfPath(n);
      cout << path_length;
      cout << "\n";
    
    }
///////////////////////////////////////////////// 資訊    
    ~Dijkstra(){
      delete [] adjacency_array;
      delete [] p;
      delete [] d;
      delete [] find_d;
      delete [] open_d;
      delete [] path;
      cout << "釋放記憶體空間\n";   
    } // 解構子 
         
  private:
    int vertices_number;
    int **adjacency_array; // adjacency Matrix
    int *d, *p;
    bool *find_d;
    bool *open_d;
    string *path; 
};

int main(){
  fstream filei;
  filei.open("adjacencyMatrix.txt", ios::in); // 讀 adjacencyMatrix.txt
  int source = 0;
  class Dijkstra g(filei);
  cout << "Dijkstra Shortest Path Algoorithm:\n";
  cout << "What is the source vertex:";
  cin >> source;
  cout << "d[i]                       p[i]                     shortest path\n";
  for(int i = 0; i < g.getVertices_number(); i++){cout << i+1 << "  ";}
  cout << "     ";
  for(int i = 0; i < g.getVertices_number(); i++){cout << i+1 << "  ";}
  cout << "\n";
  cout << "------------------------------------------------------------------------------\n";
  g.dijkstra(source - 1);
  g.not_path();
  system("pause");
  return 0;
}
