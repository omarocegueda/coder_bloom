#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

std::vector<std::vector<int64_t>> C;
void PrecomputePascalTriangle(const int N) {
  if(N<0) {
    return;
  }
  C.resize(N+1);
  C[0] = {1};
  if(N<1) {
    return;
  }
  C[1] = {1, 1};
  if(N<2) {
    return;
  }
  for(int n=2; n<=N; ++n) {
    C[n].resize(n+1);
    C[n][0] = C[n][n] = 1;
    for(int k=1; k<n; ++k) {
      C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
  }
}

// Returns the k-th combination, in lexicographical order, of N=last-first+1 elements choose M. 
void GetCombination(const int first, const int last, const int M, const int64_t k, int *out) {
  const int N = last - first + 1;
  assert(1 <= N && N <= 60);
  assert(1 <= M && M <= N);
  assert(1 <= k && k <=C[N][M]);
  if(k==1) {
    for(int i=0;i<M;++i){
      out[i] = first + i;
    }
    return;
  }
  if(k <= C[N-1][M-1]) {
    // The first C[N-1][M-1] combinations contain `first` as first element.
    out[0] = first;
    GetCombination(first+1, last, M-1, k, out+1);
    return;
  } else {
    // Discard the first C[N-1][M-1] combinations. The next C[N-1][M] combinations do not contain `first`.
    return GetCombination(first+1, last, M, k - C[N-1][M-1], out);
  }
}

void Solve(const int N, const int M, const int64_t k) {
  int *combination = new int[M];
  GetCombination(1, N, M, k, combination);
  for(int i=0;i<M;++i) {
    std::cout << combination[i] << " ";
  }
  std::cout << std::endl;
  delete[] combination;
}

int main() {
  int N, M;
  int64_t k;
  std::cin >> N >> M >> k;
  PrecomputePascalTriangle(N);
  Solve(N, M, k);
  return 0;
}
