#include <iostream>
#include <cassert>
const int points[4] = {40, 100, 300, 1200};

int main() {
  int N;
  std::cin >> N;
  int total = 0;
  for(int i=0;i<N;++i) {
    int kind;
    std:: cin >> kind;
    assert(kind!=0);
    total += points[kind-1];
  }
  std::cout << total << std::endl;
  return 0;
}