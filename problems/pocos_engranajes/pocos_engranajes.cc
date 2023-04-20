#include <algorithm>
#include <iostream>
#include <vector>


int64_t Solve(const std::vector<int64_t>& E) {
  int64_t lcm = E[0];
  for(int i=1;i<E.size();++i) {
    int64_t g = std::__gcd(lcm, E[i]);
    lcm = (lcm/g)*E[i];
  }
  return lcm;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int64_t> E(N);
  for(int i=0;i<N;++i){
    std::cin >> E[i];
  }
  std::cout << Solve(E)<< std::endl;
  return 0;
}
