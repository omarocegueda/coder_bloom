#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <fstream>

const int64_t kMod = 1000000009;

std::vector<std::vector<int64_t>> ComputePascalTriangleStandard(int64_t N) {
  std::vector<std::vector<int64_t>> T(N+1);
  T[0] = {1};
  for(int n=1;n<=N;++n) {
    T[n].resize(n+1);
    T[n][0] = T[n][n] = 1;
    for(int k=1;k<n;++k) {
      T[n][k] = (T[n-1][k] + T[n-1][k-1])%kMod;
    }
  }
  return T;
}

int main() {
  int M,N;
  std::cin >> M >> N;
  ++N; // Dont forget Carlos.
  std::cout << ComputePascalTriangleStandard(M-1)[M-1][N-1] <<std::endl;
  return 0;
}

