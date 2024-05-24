#include <fstream>  

constexpr bool isNum(const char chr) noexcept{
  return (chr >= '0' && chr <= '9');
}

unsigned getValues(){
  std::ifstream readInput("puzzle.txt");
  std::string newLine;
  int num = 0;
  unsigned int sum = 0;

  while(readInput.good()){
    std::getline(readInput,newLine);

    auto it = newLine.begin();
    auto rit = newLine.crbegin();

    while(!isNum(*it)) it++;
    num = (*it - '0')*10;

    while(!isNum(*rit)) rit++;
    num += (*rit - '0');

    sum += num;

  }
  readInput.close();
  return sum;
}

int main(){

  printf("%d\n",getValues());

  return 0;
}