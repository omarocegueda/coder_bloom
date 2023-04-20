#include <iostream>
int main() {
  int N;
  std::cin >> N;
  for(int i=1, space = 2*N - 1; i <= 2 * N; ++i, --space) {
    std::cout << std::string(space, '.');
    for(int j=0;j<i;++j) {
      std::cout << "*";
      if(j<i-1) {
        std::cout << " ";
      }
    }
    std::cout << std::string(space, '.') <<std::endl;
  }
  for(int i=0;i<N;++i) {
    std::cout << std::string(2 * N - 1, '.') << "*" << std::string(2 * N - 1, '.')<<std::endl;
  }
  return 0;
}
