#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>


std::pair<int64_t, int64_t> Solve(int N, int K, const std::vector<int>& A_) {
  std::vector<int> A = A_;
  std::sort(A.begin(), A.end());
  int64_t total = 1;
  int64_t loosing = 1;
  for(int i=0;i<N;++i) {
    total *= (A[i] + (i<K)); // Total results
    loosing *= A[i]; // Results where we do not win anything.
  }
  return {total-loosing, total};
}

int main() {
  int N, K;
  std::cin >> N >> K;
  std::vector<int> A(N, 0);
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  const auto&[winning, total] = Solve(N, K, A);
  //std::cout << winning << " " << total << std::endl;
  printf("%lld %lld\n", winning, total);
  return 0;
}

