///////////////////////////////////////////////////////////////////////////////
// 程式: External Sorting Simulator
// 目的: External Sorting 
// 日期: 2013/5/28                                  
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

typedef struct{
  int point;
  int full_nu;
}Point;

class External_Sorting{
  public:
    External_Sorting(fstream &filei_config, fstream &fileo_data){
      readConfig(filei_config);
      randData(fileo_data);
      newDiskMemory();
    } // 建構子 
//////////////////////////////建構模擬環境/////////////////////////////////////    
    void readConfig(fstream &filei_config){
      char buffer[100];
      filei_config.getline(buffer, sizeof(buffer));
      MemorySize = strtokval(buffer);
      filei_config.getline(buffer, sizeof(buffer));
      DiskSize = strtokval(buffer);     
      filei_config.getline(buffer, sizeof(buffer));
      DataSize = strtokval(buffer);
      filei_config.getline(buffer, sizeof(buffer));
      InputSize = strtokval(buffer);
      filei_config.getline(buffer, sizeof(buffer));
      OutputSize = strtokval(buffer);
      filei_config.close(); 
   } 
   int strtokval(char buffer[]){ // 切割字串 回傳值 
     char *pch;
     int n = 0;
     pch = strtok(buffer, " ");
     pch = strtok(NULL," ");
     return n=atoi(pch);
   }
   void randData(fstream &fileo_data){ // 產生亂數並寫到 fileo_data 
     int i = 0;
     while(i < DataSize){
       fileo_data << rand();
       fileo_data << " ";
       i++;
     }  
     fileo_data.close();   
   }
   void newDiskMemory(){ // 起始陣列 
     memory = new int [MemorySize]; 
     disk = new int [DiskSize];
     for(int i = 0; i < DiskSize; i++){
       disk[i] = -1;
     } 
   }
   void setRanddataToDisk(fstream &file_ir){ // 將亂數資料存到 disk 
     for(int i = 0; i < DataSize; i++ )file_ir >> disk[i];
     file_ir.close();
   }
////////////////////////////Start Run Generation(排序)///////////////////////// 
  void Generation(fstream &file_o){  
    file_o << "--------------------------" << "\n" << "Start Run Generation" << "\n";
    int block = 0;
    bool full = false;
    if(DataSize%MemorySize != 0){
      block = (DataSize/MemorySize) + 1;
    }
    else {
      block = DataSize/MemorySize;
      full = true;
    } 
    blocks = block;
    d_f = full;
    if(true == full){
      fullmemorysort(block, file_o);
      file_o << "Run Generation finished." << "\n" << "--------------------------" << "\n";
    }
    if(false == full){
      notfullmemorysort(block, DataSize%MemorySize, file_o);
      file_o << "Run Generation finished." << "\n" << "--------------------------" << "\n";
    }
  }
  void fullmemorysort(int block, fstream &file_o){ // DataSize/MemorySize剛好整除  
    int j = 0, i = 0, s_h = DataSize, m = 0;
    for(int b = 1; b <= block; b++){  // 排序次數    
      i = 0;
      file_o << "Run " << b << ":" << "\n";
      while(j < b * MemorySize){ // 將disk的資料放到memory中 
        memory[i] = disk[j];
        i++; j++;    
      }
      file_o << "Original Data: ";  
      fileoutmemory(file_o);
      quicksort(memory, 0, MemorySize - 1); // 排序
      file_o << "Sorted Data: ";
      fileoutmemory(file_o);
      m = 0;
      while(m < MemorySize){ // 存回disk
        disk[s_h] = memory[m];
        s_h++; m++;    
      }           
    }
  }
  void notfullmemorysort(int block, int n, fstream &file_o){ // DataSize/MemorySize有餘數 
    fullmemorysort(block - 1, file_o);
    int h = (block - 1) * MemorySize;
    file_o << "Run " << block << ":" << "\n";
    file_o << "Original Data: ";  
    for(int i = 0; i < MemorySize; i++) memory[i] = -1;   
    for(int i = 0; i < n; i++){
      memory[i] = disk[h];
      h++;
    }
    quicksort(memory, 0, MemorySize - 1);
    file_o << "Sorted Data: ";
    fileoutmemory(file_o);
    int s_h = DataSize + (MemorySize * (block - 1)), m = 0, j = 0;
    d_f_n = 0;
    while(j < n){
      if(-1 == memory[m])m++; 
      else{
        disk[s_h] = memory[m];
        m++; j++; s_h++; d_f_n++;
      }
    }
  }
  void quicksort(int a[], int left, int right){  // quick sort
    if (left >= right) return;
    int i = left, j = right;
    int  key = a[i],tmp;
    while (1) {
      while (a[j] > key) j--;
      while (a[i] < key) i++;
      if(i >= j) break;
      tmp = a[i]; a[i] = a[j]; a[j] = tmp;
      i++;j--;
     }
     if(left  < i - 1)   quicksort(a, left, i - 1);
     if(j + 1 < right)  quicksort(a, j + 1 , right);   
  }    
/////////////////////////////////Run Merging///////////////////////////////////

  void Run_Merging(fstream &file_o){
    char pass_c[] = {'R', 'S', 'T', 'U', 'V', 'W'};
    int b = blocks;
    int pass = 0;
    int ia = 0, ib = 0, o = 0;
    while(b != 1){
      file_o << "Pass" << pass + 1 << ": " << pass_c[pass] << " -> " << pass_c[pass + 1] << "\n";
      pass++;
      if(0 == b%2){
        for(int i = 1; i <= b; i+=2){ //　取2個　blocks　做　Merge  
          ia = i; ib = i + 1;  //　紀錄是第幾個　blocks
          file_o << "Merge " << pass_c[pass - 1] << ia << " and " << pass_c[pass - 1] << ib << " -> " << pass_c[pass] << pass << "\n";  
          Merge_sorting(ia, ib, o, pass, file_o);           
          o++; // 紀錄output blocks
        }
        b = b/2; //　Merge結束後　blocks　個數   
      }
      else{ // blocks 為基數個 
        for(int i = 1; i < b; i+=2){ //　取2個　blocks　做　Merge  
          ia = i; ib = i + 1;  //　紀錄是第幾個　blocks         
          file_o << "Merge " << pass_c[pass - 1] << ia << " and " << pass_c[pass - 1] << ib << " -> " << pass_c[pass] << pass << "\n"; 
          Merge_sorting(ia, ib, o, pass, file_o);
          o++; // 紀錄output blocks 
        }
        int input_f = 0, output_f = 0;
        if(pass%2 != 0){
          input_f = ((b-1) * (MemorySize * pass));
          output_f = (DiskSize/2) + (o * (MemorySize * (pass+1)));
        }
        else{
          input_f = (DiskSize/2) + ((b-1) * (MemorySize * pass)); 
          output_f =(o * (MemorySize * (pass)));    
        }
        for(int m = 0; m < MemorySize * pass; m++ ){
          disk[output_f] = disk[input_f];
          input_f++;
          output_f++;
        }
        o++;
        b = (b / 2) + 1; //　Merge結束後　blocks　個數             
      }
      o = 0;
    }
  }

  void Merge_sorting(int ia, int ib, int o, int pass, fstream &file_o){
    char pass_c[] = {'R', 'S', 'T', 'U', 'V', 'W'};  
    Point output, input0, input1; 
    int b1 = 0, b2 = 0; 
    if(pass%2 == 0){ // output 下
      input0.point = 0 + ((ia - 1) * (MemorySize * pass));
      input1.point = ((ib - 1) * (MemorySize * pass));
      input0.full_nu = InputSize/2;
      input1.full_nu = InputSize/2;
      output.point = DiskSize/2;
      output.full_nu = OutputSize;
    }
    else{
      input0.point = (DiskSize/2) + ((ia - 1) * (MemorySize * pass));
      input1.point = (DiskSize/2) + ((ib - 1) * (MemorySize * pass));
      input0.full_nu = InputSize/2;
      input1.full_nu = InputSize/2;         
      output.point = 0;
      output.full_nu = OutputSize;
    } 
    output.point += (o * (MemorySize * pass*2));
    b1 = MemorySize * pass;
    b2 = MemorySize * pass;
    int p_input0 = input0.point;
    file_o << "      Input 0 data: ";
    for(int i = 0; i < b1; i++){
      cout << disk[p_input0] << ", ";
      file_o << disk[p_input0] << ", ";
      p_input0++;
    }
    file_o << "\n";
    int p_input1 = input1.point;
    file_o << "      Input 1 data: ";
    for(int i = 0; i < b2; i++){
      file_o << disk[p_input1] << ", ";
      p_input1++;
    }
    file_o << "\n";
    file_o << pass_c[pass] << o +1 << "\n";
    do{         
      if(disk[input0.point] <= disk[input1.point]){
        disk[output.point] = disk[input0.point];
        file_o <<  disk[input0.point] << " ";
        input0.point++;
        output.point++;
        b1--;
      }
      else{
        disk[output.point] = disk[input1.point];
        file_o <<  disk[input1.point] << " ";
        input1.point++; 
        output.point++;
        b2--;      
      }
      
    }while( (b2!=0) && (b1!=0));
    if(b1 != 0){
        while(b1 != 0){
          disk[output.point] = disk[input0.point];
          file_o << disk[input0.point] << " ";
          output.point++;
          input0.point++;
          b1--;
        }
      }   
      if(b2 != 0){
        while(b2 != 0){
          disk[output.point] = disk[input1.point];
          file_o <<  disk[input1.point] << " ";
          output.point++;
          input1.point++;
          b2--;
        }
      } 
    file_o << "\n";
  }
 
//////////////////////////////////列印資訊//////////////////////////////////////   
   void printdisk(){
     for(int i = 0; i < DiskSize; i++)cout << disk[i] << " "; 
     cout << "\n"; 
   }
   void printmemory(){
     for(int i = 0; i < MemorySize; i++)cout << memory[i] << " ";
     cout << "\n";  
   }   
   void fileoutmemory(fstream &file_o){
     for(int i = 0; i < MemorySize; i++)file_o << memory[i] << " ";
     file_o << "\n";  
   }    
            
  private:
    int MemorySize; 
    int DiskSize; 
    int DataSize; 
    int InputSize; 
    int OutputSize; 
    int *memory;
    int *disk;
    int blocks;
    bool d_f;
    int d_f_n; 
};

///////////////////////////////////主程式//////////////////////////////////////
int main(){
  fstream filei_config, fileo_data, file_ir, file_o;
  srand(time(NULL));
  filei_config.open("simu_config.txt", ios::in); 
  fileo_data.open("DS_B10002057_data.txt", ios::out); 
  class External_Sorting e(filei_config, fileo_data);
  file_ir.open("DS_B10002057_data.txt", ios::in); 
  e.setRanddataToDisk(file_ir);
  file_o.open("DS_B01234567_result.txt", ios::out);
  e.Generation(file_o);
  e.Run_Merging(file_o);
  file_o.close();
  system("pause");
  return 0;
}
/*
b. The algorithm of this program
1.開simu_config檔取得MemorySize、DiskSize、DataSize、InputSize、OutputSize 的值，並利用DataSize，產生一個data.txt內容為DataSize個亂數。
2.計算此筆資料有多少個blocks，把每塊blocks放到memory中做排序，再存回disk。
使用的排序: quick sort
虛擬碼:
  void quicksort(Type data[1..n],  Index left,  Index right){  
    if (left >= right) return;
    Index key = data [i];
    Index i = left;
    Index j = right;
    
    while (1) {
      while (data [j] > key) j--;
      while (data [i] < key) i++;
      if(i >= j) break;
      exchange data[i] and data[j]
      i++; 
      j--;
    }
     if(left  < i - 1)   quicksort(a, left, i - 1);
     if(j + 1 < right)  quicksort(a, j + 1 , right);   
  }  
3.將Memory  分成Input0、Input1、 Output 三個區塊，每次從排序好的block中取兩個區塊做Merg，Merg出的資料放到Output區，如果Output區滿的話將資料回到disk中，重複上述的動作，直到block合併為一塊，就完成排序。


d. Any difficulties encountered
  1. Merg需要做幾階
  2. 實作Merg來排序的部分
e. How you resolved the problems
  1.原本想推公式，但之後放棄了，之後是用while(black!= 1){}來做的，當black合併到剩下一時代表Merg結束。每Merg一次black = black/2。
2.我宣告了一堆變數，來記錄所需要紀錄的位置，免強能做出排序，但程式碼繁瑣，且不是測試所有值都會正確，目前我想不到其他方法。



*/ 
