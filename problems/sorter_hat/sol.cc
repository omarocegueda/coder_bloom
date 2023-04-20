#include <iostream>
#include <vector>

int64_t SolveSlow(int64_t N, int64_t C) {
  std::vector<int64_t> v[2];
  v[0].resize(N+C);
  v[1].resize(N+C);
  v[0][0] = v[1][0] = v[1][1] = 1;
  for(int n = 2; n<N+C; ++n) {
    std::vector<int64_t> &prev = v[1-n%2];
    std::vector<int64_t> &current = v[n%2];
    for(int k=1; k<=n; ++k) {
      current[k] = prev[k-1] + prev[k];
    }
  }
  std::vector<int64_t> &sol = v[(N+C-1)%2];
  return sol[C-1];
}

int main() {
  int64_t N, C;
  std::cin >> N >> C;
  std::cout << SolveSlow(N, C) << std::endl;
  return 0;
}
