///////////////////////////////////////////////////////////////////////////////
// �ت�: Shortest Path 
// ����: A Star Search Algorithm
// ���: 2013/4/10                                 
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define MAX 1000  
using namespace std;
char str[26];

class QueueData{
	public:
	int index; // �`�I 
	float cost; // F() 
	int last; // ���`�I 
};
class PathData{
	public:
	int point; // �`�I 
	float cost; // ��ثe�������(���]�t�����w������)  
};
class A_Star{
  public:
  	A_Star(fstream &filei, int n){
	  char buffer[100];
	  setVertices_number(n);
	  filei.getline(buffer,sizeof(buffer)); // ��@��
	  newArray();
	  setAdjacency_array(filei);
	  setH(filei);
	}	
    void setVertices_number(int n){vertices_number = n;}
    int getVertices_number(){return vertices_number;}		

    void newArray(){      
      adjacency_array = new float*[getVertices_number()];
      for(int i = 0; i < getVertices_number(); i++)adjacency_array[i] = new float[getVertices_number()];
      for(int i = 0; i < getVertices_number(); i++){ 
        for(int j = 0; j < getVertices_number(); j++)adjacency_array[i][j] = MAX;
      }
      h = new float[getVertices_number()];
      path = new PathData[getVertices_number()];
      qdata = new QueueData[getVertices_number()*2];
      for(int i = 0; i < getVertices_number(); i++) qdata[i].index = -1;
      for(int i = 0; i < getVertices_number(); i++) path[i].point = -1;
    }
    void setAdjacency_array(fstream &filei){
      char buffer[100], *pch;
      int count = 0, a = 0;
      float tof;
      while( count < getVertices_number()){       
        filei.getline(buffer,sizeof(buffer));
        a = 0;
        pch = strtok(buffer, " ");
        while(pch!=NULL){
		  sscanf(pch,"%f",&tof);
          if(tof!=0){adjacency_array[count][a] = tof;}
          a++; 
          pch = strtok(NULL," ");              
        }
        count++;
      }    
    }
    void setH(fstream &filei){
	  char buffer[100], *pch; 
	  int a = 0;
	  float tof; 
	  filei.getline(buffer,sizeof(buffer));
	  pch = strtok(buffer, " ");
	  while(pch!=NULL){  
		sscanf(pch,"%f",&tof);
	  	h[a++] = tof;
	  	pch = strtok(NULL," "); 
	  }
	}
///////////////////////////////////////////////////////////////////////////////
  void Algorithm(){
    int qdata_num = 0, point = 0, pathlen = 0, iteration = 0;
    float f = 0;
    path[pathlen].point = point; // �N�_�I�s�쵲�G���}�C
	path[pathlen].cost = 0;
	//
	cout << "    " << iteration << "                           " << str[iteration] << " = " << h[iteration] << "\n"; 
    pathlen++; // ���G���}�C = 1
    while(point != getVertices_number()-1){  // ���٨S������I�� 
	  for(int i = 0; i < getVertices_number(); i++){  // ���Ҧ����I  
	    if(adjacency_array[point][i] != MAX){  // ��ਫ�����|  
		  f = path[pathlen-1].cost  + adjacency_array[point][i] + h[i]; // �p��̲צ��� 
          qdata[qdata_num].index = i;
          qdata[qdata_num].cost = f;
          qdata[qdata_num].last = point;
          qdata_num++;	// �s��Queue��	     
		}
	  }// ���Ҧ��i�������|
	  cout << "    " << ++iteration << "              " << str[path[pathlen-1].point] << "            ";
	  printqdata(); 
	  // ��Queue���̤p�� 
	  QueueData swap;
	  for(int j = 0; j < qdata_num - 1; j++){
		for(int k = qdata_num - 1; k > j; k--){
	      if(qdata[k-1].cost < qdata[k].cost){ 
            swap = qdata[k-1]; qdata[k-1] = qdata[k]; qdata[k] = swap;
		  }
	    }	  
	  } // �Ƨ� 
	  while(qdata[qdata_num - 1].last!=path[pathlen - 1].point){
		path[pathlen - 1].point=-1;
	    pathlen--;
	  }	 // �^�������`�I�@ 
	  path[pathlen].point = qdata[qdata_num - 1].index; // �N�̤p�Ȫ��I�s�쵲�G���}�C
      path[pathlen].cost = qdata[qdata_num-1].cost - h[qdata[qdata_num - 1].index]; 
	    // ���ثe�������(���]�t�����w������) 
      pathlen++; // ���G���}�C++
      qdata[qdata_num - 1].index = -1; // �N Queue�����̤p�Ȯ��� 
      point = path[pathlen-1].point; // �N point ���V������Ӹ`�I 
      qdata_num--;
	}
	cout << "    " << ++iteration << "              " << str[path[pathlen-1].point] << "\n"; 
  }				
///////////////////////////////////�L�X��T/////////////////////////////////////	
  void printpath(){
	cout << "Shortest Path : ";
    for(int i = 0; i < getVertices_number(); i++){
	  if(path[i].point!=-1 && path[i].point!=getVertices_number()-1){
		cout << str[path[i].point] << " - ";
	  }
	  if(path[i].point!=-1 && path[i].point==getVertices_number()-1){
		cout << str[path[i].point];
	  }	
	}cout << "\n";			
  }
  void printqdata(){
    for(int i = 0; i < getVertices_number(); i++){
	  if(qdata[i].index!=-1){
		cout << str[qdata[i].index] << " = " << qdata[i].cost << "; ";
	  }	
	}cout << "\n";	 
  }   
  private:
	int vertices_number; 
	float **adjacency_array;
	float *h;  // ���|�w�� 
	PathData *path;  // �s���G
	QueueData *qdata;
};

int main(){
  fstream filei;
  int n;
  for(int i = 0; i < 26; i++){
	if(i == 0){str[i] = 'S';}
	else{str[i] = 'A'+ (i - 1);}
  }
  filei.open("m.txt", ios::in); 
  filei >> n;
  class A_Star a(filei, n);
  cout << "iteration     node expanded     Priority queue at end of this iteration\n"; 
  a.Algorithm();
  a.printpath();  
  system("pause");
  return 0;
}
