#include <iostream>
#include <vector>
using namespace std;
int RECEIVE_DATA_SIZE = 24;
int main() {
  uint8_t Receive_Data_Pr[RECEIVE_DATA_SIZE] = {0};
  cout << "sizeof(Receive_Data_Pr) = " << sizeof(Receive_Data_Pr)
       << endl; //读串口数据
}