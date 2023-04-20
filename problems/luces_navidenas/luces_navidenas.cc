#include <algorithm>
#include <vector>
#include <iostream>

int main() {
  int N;
  std::cin >>  N;
  std::vector<int> C(N);
  for(int i=0;i<N;++i) {
    std::cin >> C[i];
    C[i]--;
  } 
  std::sort(C.begin(), C.end());
  int kmax=C[0];
  for(int i=1;i<N;++i) {
    int opt = C[i] / (i+1);
    kmax = std::min(kmax, opt); 
  }
  std::cout << N + kmax*(N*(N+1)/2) << std::endl;
  return 0;
}

