#include <algorithm>
#include <iostream>

int64_t Solve(const int64_t C, const int64_t N) {
  int64_t M = N;
  while(std::__gcd(C, M)>1) {
    ++M;
  }
  return M;
}

int main() {
  int64_t C, N;
  std::cin >> C >> N;
  std::cout << Solve(C, N) << std::endl;
  return 0;
}
