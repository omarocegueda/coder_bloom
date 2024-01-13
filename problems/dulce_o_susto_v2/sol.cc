#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

int32_t SolveLinear(const int32_t N, const std::vector<int32_t>& C, const std::vector<int32_t>& S) {
  int32_t candies = 0;
  int32_t i = 0;
  int32_t j = 0;
  while(i<N) {
    while(i<N && S[i]<C[j]) {
      ++i;
    }
    if(i<N) {
      // We know C[j]<=S[i]. Assign it and get a candy
      ++j;
      ++i;
      ++candies;
    } 
  }
  return candies;
}

void Solve() {
  int32_t N;
  std::cin >> N;
  std::vector<int32_t> C(N);
  std::vector<int32_t> S(N);
  for(int i=0;i<N;++i) {
    std::cin >> C[i];
  }
  for(int i=0;i<N;++i) {
    std::cin >> S[i];
  }
  std::sort(C.begin(), C.end());
  std::sort(S.begin(), S.end());
  int32_t sol = SolveLinear(N, C, S);
  std::cout << sol << std::endl;
}

int main() {
  Solve();
  return 0;
}
