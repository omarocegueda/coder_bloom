#include <algorithm>
#include <iostream>
#include <vector>

int32_t Solve(const int32_t N, const int32_t D, const std::vector<int32_t>& K) {
  int32_t prev_door = K[0]-D-1;
  int32_t n_doors = 0;
  for(int32_t k: K) {
    if(k <= prev_door + D) {
      continue;
    }
    ++n_doors;
    prev_door = k + D;
  }
  return n_doors;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int32_t N, D;
  std::cin >> N >> D;

  std::vector<int32_t> K(N);
  for(int i=0;i<N;++i) {
    std::cin >> K[i];
  }
  std::sort(K.begin(), K.end());
  int32_t sol = Solve(N, D, K);
  std::cout << sol << std::endl;
  return 0;
}