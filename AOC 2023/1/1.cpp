#include <iostream>
#include <fstream>  
#include <vector>
#include <algorithm>
#include <numeric>

constexpr bool isNum(const char chr){
  return (chr >= '0' && chr <= '9');
}

constexpr void getNum(const int idx,const int final,const std::vector<std::string>& arr,std::vector<int>& arrNum){
  if(idx==final) return;
  int num = 0;

  auto it = arr[idx].begin();
  auto rit = arr[idx].crbegin();

  while(!isNum(*it)) it++;
  num = (*it - '0')*10;

  while(!isNum(*rit)) rit++;
  num += (*rit - '0');

  arrNum.push_back(num);
  return getNum(idx+1,final,arr,arrNum);
}

void getStrings(std::vector<std::string>& arr){
  std::ifstream readInput("puzzle.txt");
  std::string newLine;
  while(readInput.good()){
    std::getline(readInput,newLine);
    arr.push_back(newLine);
  }
  readInput.close();

}

int main(){
  std::vector<std::string> arr;
  std::vector<int> arrNum;
  getStrings(arr);
  arrNum.reserve(arr.size());

  getNum(0,arr.size(),arr,arrNum);

  printf("%d\n",std::accumulate(arrNum.begin(),arrNum.end(),0));

  return 0;
}