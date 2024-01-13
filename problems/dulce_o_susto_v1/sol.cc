#include <algorithm>
#include <iostream>
#include <vector>

int64_t SolveLinear(const int32_t c, const int32_t n, std::vector<int32_t> C, std::vector<int32_t> N) {
  std::sort(C.begin(), C.end());
  std::sort(N.begin(), N.end());
  int32_t i=0;
  int32_t j=0;
  int64_t candies = 0;
  while(i<n) {
    while(j<c && C[j]<=N[i]) {
      ++j;
    }
    candies += j;
    ++i;
  }
  return candies;
}

int64_t SolveQuadratic(const int32_t c_, const int32_t n_, const std::vector<int32_t>& C, const std::vector<int32_t>& N) {
  int64_t candies = 0;
  for(int32_t n : N) {
    for(int32_t c : C) {
      if(c<=n) {
        ++candies;
      }
    }
  }
  return candies;
}


void Solve() {
  int32_t c, n;
  std::cin >> c >> n;
  std::vector<int32_t> C(c);
  std::vector<int32_t> N(n);
  for(int i=0;i<c;++i) {
    std::cin >> C[i];
  }
  for(int i=0;i<n;++i) {
    std::cin >> N[i];
  }
  std::cout << SolveLinear(c, n, C, N) << std::endl;
}

int main() {
  Solve();
  return 0;
}