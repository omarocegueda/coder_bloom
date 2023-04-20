#include <iostream>
#include <sstream>
int64_t Solve(const int64_t N,int64_t R, const int64_t B) {  
  if(R>B) {
    R = B;
  }
  return (N*R)/B;
}

int main() {
  int64_t N, R, B;
  std::cin >> N >> R >> B;
  std::cout << Solve(N, R, B) << std::endl;
  return 0;
}
