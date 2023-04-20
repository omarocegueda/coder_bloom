#include <iostream>
#include <string>
#include <vector>
#include <sstream>

const int kMaxN = 500;
const int kMaxFamilyTypes = 26;
int I[kMaxN+1][kMaxN+1][kMaxFamilyTypes];

void PrecomputeIntegral(const int N, const std::vector<std::string>& A, const int family=-1) {
  if(family==-1) {
    for(int k=0;k<kMaxFamilyTypes;++k) {
      PrecomputeIntegral(N, A, k);
    }
    return;
  }
  for(int i=0; i<=N; ++i) {
    for(int j=0; j<=N; ++j) {
      I[i][j][family] = 0;
    }
  }
  // First row
  for(int j=1; j<=N; ++j) {
    const bool observed = family == (A[0][j-1]-'A');
    I[1][j][family] = I[1][j-1][family] + observed;
  }
  // Rest of rows
  for(int i=2; i<=N; ++i) {
    for(int j=1; j<=N;++j) {
      const int observed = (family == (A[i-1][j-1]-'A'));
      const int top =  I[i-1][j][family];
      const int left = I[i][j-1][family];
      const int intersection = I[i-1][j-1][family];
      I[i][j][family] = top+left-intersection+observed;
    }
  }
}

int CountDistinctFamilies(const int end_row, const int end_col, const int side) {
  int n_observed = 0;
  for(int k=0;k<kMaxFamilyTypes;++k) {
    const int top = I[end_row-side][end_col][k];
    const int left = I[end_row][end_col-side][k];
    const int intersection = I[end_row-side][end_col-side][k];
    const int total = I[end_row][end_col][k] - top - left + intersection;
    n_observed += (total>0);
  }
  return n_observed;
}

bool Possible(const int N, const int distinct_families, const int side) {
  for(int end_row=side; end_row<=N; ++end_row) {
    for(int end_col=side; end_col<=N; ++end_col) {
      const int n_observed = CountDistinctFamilies(end_row, end_col, side);
      if(n_observed >= distinct_families) {
        return true;
      }
    }
  }
  return false;
}

int Solve(const int N, const std::vector<std::string>& A) {
  PrecomputeIntegral(N, A);
  const int distinct_families = CountDistinctFamilies(N, N, N);
  if(distinct_families <= 1) {
    return distinct_families;
  }
  int a = 0; // impossible
  int b = N; // possible
  while(a + 1 < b) {
    int mid = (a + b) / 2;
    if(Possible(N, distinct_families, mid)) {
      b=mid;
    } else {
      a = mid;
    }
  }
  return b;
}

void Solve() {
  int N;
  std::cin >> N;
  std::vector<std::string> A(N, "");
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << Solve(N, A) << std::endl;
}

int main() {
  Solve();
  return 0;
}
