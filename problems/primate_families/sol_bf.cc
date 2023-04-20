#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

const int kMaxN = 500;
const int kMaxFamilyTypes = 26;
int I[kMaxN+1][kMaxN+1][kMaxFamilyTypes];

int CountDistinctFamiliesBruteForce(const int N, const std::vector<std::string>& A, const int end_row, const int end_col, const int side) {
  std::vector<bool> found(kMaxFamilyTypes, false);
  int n_found = 0;
  for(int i=end_row-side;i<end_row;++i) {
    for(int j=end_col-side;j<end_col;++j) {
      const int observed=A[i][j] - 'A';
      if(observed<0 || observed>kMaxFamilyTypes) {
        continue;
      }
      if(!found[observed]) {
        ++n_found;
        found[observed] = true;
      }
    }
  }
  return n_found;
}

bool PossibleBruteForce(const int N, const std::vector<std::string>& A, const int distinct_families, const int side) {
  for(int end_row=side;end_row<=N;++end_row) {
    for(int end_col=side;end_col<=N;++end_col) {
      const int n_found = CountDistinctFamiliesBruteForce(N, A, end_row, end_col, side);
      if(n_found>=distinct_families) {
        return true;
      }
    }
  }
  return false;
}

int SolveBruteForce(const int N, const std::vector<std::string>& A) {
  const int distinct_families = CountDistinctFamiliesBruteForce(N, A, N, N, N);
  if(distinct_families<=1) {
    return distinct_families;
  }
  for(int side=2; side<N;++side) {
    if(PossibleBruteForce(N, A, distinct_families, side)) {
      return side;
    }
  }
  return N;
}

void SolveBruteForce() {
  int N;
  std::cin >> N;
  std::vector<std::string> A(N, "");
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << SolveBruteForce(N, A) << std::endl;
}

int main() {
  SolveBruteForce();
  return 0;
}
