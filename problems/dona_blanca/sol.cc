#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <limits>


int32_t StrengthNeeded(const int32_t N, const int32_t K, const std::vector<int32_t>& R, const int32_t P) {
  assert(0<=P && P<R.size());
  int32_t g = std::__gcd(N, K);
  int32_t min_resistance = std::numeric_limits<int32_t>::max();
  for(int i=0, p=P; i<N; ++i, p=(p+g)%N) {
    min_resistance = std::min(min_resistance, R[p]);
  }
  return min_resistance + 1;
}

std::vector<int32_t> SolveSlow(const int32_t N, const int32_t K, const std::vector<int32_t>&R, const int32_t M, const std::vector<int32_t>& P) {
  std::vector<int32_t> S(M);
  for(int32_t j=0; j<M; ++j) {
    S[j] = StrengthNeeded(N, K,  R, P[j]);
  }
  return S;
}

void Solve() {
  int32_t N, K;
  std::cin >> N >> K;
  assert(1<=N && N<=100000);
  assert(1<=K && K<=N);
  std::vector<int32_t> R(N);
  for(int32_t i=0; i<N; ++i) {
    std::cin >> R[i];
  }
  int32_t M;
  std::cin >> M;
  std::vector<int32_t> P(M);
  for(int32_t j=0; j<M;++j) {
    std::cin >> P[j];
    --P[j];
  }
  std::vector<int32_t> sol = SolveSlow(N, K, R, M, P);
  for(const int32_t s : sol) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}

int main() {
  Solve();
  return 0;
}

