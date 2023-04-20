#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<char> valid = {'<','>','+','-','.',',','[',']'};
  std::string line;
  std::getline(std::cin, line);
  for(const char c : line) {
    if(valid.find()!=valid.end()) {
      std::cout<<c;
    }
  }
  return 0;
}
