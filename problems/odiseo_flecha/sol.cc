#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>

int32_t Solve(const int32_t B, const int32_t N, const std::vector<int32_t>& X, const std::vector<int32_t>& Y) {
  std::map<int64_t, int32_t> M;
  for(int i=0;i<N;++i) {
    const int32_t g = std::gcd((Y[i]-B), X[i]);
    const int64_t key = (static_cast<int64_t>((Y[i]-B)/g)<<32) | (X[i]/g);
    M[key] ++;
  }
  int32_t best = 0;
  for(const auto& count : M) {
    best = std::max(best, count.second);
  }
  return best;
}

int32_t SolveSlow(const int32_t B, const int32_t N, const std::vector<int32_t>& X, const std::vector<int32_t>& Y) {
  int best = 0;
  for(int i=0;i<N;++i) {
    const int64_t dxi = X[i];
    const int64_t dyi = Y[i] - B;
    int opt = 1;
    for(int j=i+1;j<N;++j) {
      const int64_t dxj = X[j];
      const int64_t dyj = Y[j] - B;
      if(dyi * dxj == dxi * dyj) {
        ++opt;
      }
    }
    if(best < opt) {
      best = opt;
    }
  }
  return best;
}


int main() {
  int32_t B, N;
  std::cin >> B >> N;
  std::vector<int32_t> X(N);
  std::vector<int32_t> Y(N);
  for(int32_t i=0;i<N;++i) {
    std::cin >> X[i] >> Y[i];
  }
  std::cout << SolveSlow(B, N, X, Y) << std::endl;
  return 0;
}
