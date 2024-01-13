#include <iostream>
#include <algorithm>
int main() {
  int N;
  std::cin>> N;
  int sum = 0;
  for(int i=0;i<N;++i) {
    int a, c;
    std::cin >> a >> c;
    sum += std::min(a,c);
  }
  return 0;
}