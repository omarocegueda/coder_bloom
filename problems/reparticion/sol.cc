#include <string.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

const int kMaxGifts = 2000;
int M[kMaxGifts+1][kMaxGifts+1];

int Solve(const int N, const std::vector<int>& A, const std::vector<int>& B) {
  memset(M, -1, sizeof(M));
  M[1][0] = B[0]; // We only have 1 gift, and A must get exactly zero gifts ==> B will get the gift.
  M[1][1] = A[0]; // We only have 1 gift, and A must get exactly one gift ==> A will get the gift.
  for(int n=2;n<=N;++n) {
    for(int k=0;k<=n;++k) {
      // We have n gifts, and A must get exactly k of them.
      // Option 1: A gets the last gift.
      int best = -1;
      int selected = -1;
      if(k>0) { // A must be forced to get at least one gift.
        assert(M[n-1][k-1] >=0 );
        const int opt1 = A[n-1] + M[n-1][k-1];
        if(best==-1 || opt1 < best) {
          best = opt1;
          selected = 0;
        }
      }
      // Option 2: B gets the last gift.
      if(k<n) { // A must not be forced to get all gifts (so we need k<n)
        assert(M[n-1][k] >=0 );
        const int opt2 = B[n-1] + M[n-1][k];
        if(best==-1 || opt2 < best) {
          best = opt2;
          selected = 1;
        }
      }
      M[n][k] = best;
    }
  }
  return M[N][N/2];
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(2*N);
  std::vector<int> B(2*N);
  for(int i=0;i<2*N;++i) {
    std::cin >> A[i] >> B[i];
  }  
  std::cout << Solve(2*N, A, B) << std::endl;
  return 0;
}


