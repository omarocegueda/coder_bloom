#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <limits>


std::vector<int32_t> SolveFast(const int32_t N, const int32_t K, const std::vector<int32_t>&R, const int32_t M, const std::vector<int32_t>& P) {
  // Precompute minimum resistance per group.
  int32_t g = std::__gcd(N, K);
  std::vector<int32_t> min_resistance(g, std::numeric_limits<int32_t>::max());
  for(int i=0;i<N;++i) {
    const int32_t r = i%g;
    min_resistance[r] = std::min(min_resistance[r], R[i]);
  }

  // Lookup solutions.
  std::vector<int32_t> S(M);
  for(int32_t j=0; j<M; ++j) {
    S[j] = 1 + min_resistance[P[j]%g];
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
  std::vector<int32_t> sol = SolveFast(N, K, R, M, P);
  for(const int32_t s : sol) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}

int main() {
  Solve();
  return 0;
}

