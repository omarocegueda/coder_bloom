#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>

bool Solve(const int64_t N, const int64_t G, const int64_t K) {
  assert(N<=1000000000000);
  assert(G<=1000000000000);
  assert(K<=N);
  return K%std::__gcd(N, G) == 0;
}

void SolveSingle() {
  int64_t N, G, K;
  std::cin >> N >> G >> K;
  std::cout << (Solve(N, G, K)?"SI":"NO") << std::endl;
}

int main(){
  SolveSingle();
  return 0;
}

