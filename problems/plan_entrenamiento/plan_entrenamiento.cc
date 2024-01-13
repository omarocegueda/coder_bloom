#include <iostream>
#include <vector>

bool Feasible(const std::vector<int32_t>&L, const int32_t delta, const int32_t M) {
  int32_t needed = 0;
  for(int i=1;i<L.size();++i) {
    needed += (L[i] - L[i-1] + delta - 1) / delta - 1;
  }
  return needed<=M;
}

int main() {
  int32_t N, M;
  std::cin >> N >> M;
  std::vector<int32_t> L(N);
  for(int32_t i=0; i<N; ++i) {
    std::cin >> L[i];
  }

  int32_t a = 0;
  int32_t b = L[N-1] - L[0];
  while(a+1<b) {
    int32_t mid = (b+a)/2;
    if(Feasible(L, mid, M)) {
      b = mid;
    } else {
      a = mid;
    }
  }
  
  std::cout << b << std::endl;
  return 0;
}