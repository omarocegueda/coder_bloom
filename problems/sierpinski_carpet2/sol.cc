#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>
#include <random>

// Returns the color of the NxN Sierpinski's carpet at (r, c)
char SierpinskiCarpetColor(const uint64_t N, uint64_t r, uint64_t c) {
  if(N == 1) {
    return '.'; 
  }
  assert(N%3==0);
  uint64_t k = N/3;
  uint64_t ii = r/k;
  uint64_t jj = c/k;
  if(ii==1 && jj==1) {
    return 'X';
  }
  return SierpinskiCarpetColor(k, r%k, c%k);
}

void SolveSingle() {
  uint64_t N;
  uint64_t L;
  std::cin >> N >> L;
  for(uint64_t i=0;i<L;++i) {
    uint64_t r, c;
    std::cin >> r >> c;
    --r;
    --c;
    assert(r >= 0);
    assert(c >= 0);
    assert(r < N);
    assert(c < N);
    std::cout << SierpinskiCarpetColor(N, r, c);
  }
  std::cout<<std::endl;
}

int main(){
  SolveSingle();
  return 0;
}
