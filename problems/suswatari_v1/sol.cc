#include <algorithm>
#include <iostream>
#include <cassert>

void Solve() {
  int N, S;
  std::cin >> N >> S;
  assert(1<=N && N<=1000);
  assert(1<=S && S<=1000);
  int max_c = 0;
  for(int i=0;i<N;++i) {
    int c;
    std::cin >> c;
    assert(1<=c && c<=1000000000);
    max_c = std::max(max_c, c);
  }
  std::cout << (max_c+S-1)/S << std::endl;
}

int main() {
  Solve();
  return 0;
}

