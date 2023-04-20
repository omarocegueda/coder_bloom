#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

int GetMinCapacity(const std::vector<int>& C, int a, int b) {
  int min_cap = C[a];
  for(int i=a; i<=b; ++i) {
    min_cap = std::min(min_cap, C[i]);
  }
  return min_cap;
}

int GetMaxContentSlowest(const std::vector<int>& C, const std::vector<int>&A, int target) {
  const int N = C.size();
  int total_transported = 0;
  for(int i=0; i < target; ++i) {
    int min_cap = GetMinCapacity(C, i, target);
    total_transported+= std::min(A[i], min_cap);
  }
  
  for(int i=target+1; i < N; ++i) {
    int min_cap = GetMinCapacity(C, target, i);
    total_transported+= std::min(A[i], min_cap);
  }
  return std::min(C[target], A[target] + total_transported);
}

int GetMaxContentSlow(const std::vector<int>& C, const std::vector<int>&A, int target) {
  const int N = C.size();
  int total_transported = 0;
  int min_cap = C[target];
  for(int i=target-1; i >= 0; --i) {
    min_cap = std::min(min_cap, C[i]);
    total_transported+= std::min(A[i], min_cap);
  }
  min_cap = C[target];
  for(int i=target+1; i < N; ++i) {
    min_cap = std::min(min_cap, C[i]);
    total_transported+= std::min(A[i], min_cap);
  }
  return std::min(C[target], A[target] + total_transported);
}

int SolveSlow(const std::vector<int>& C, const std::vector<int>&A) {
  const int N = C.size();
  int best = 0;
  for(int target = 0; target < N; ++target) {
    best = std::max(best, GetMaxContentSlowest(C, A, target));
  }
  return best;
}

int SolveWrong(const std::vector<int>& C, const std::vector<int>&A) {
  const int N = C.size();
  int target = 0;
  // Select the container with the largest content
  for(int i=1;i<N;++i) {
    if(A[target] < A[i]) {
      target = i;
    }
  }
  return GetMaxContentSlow(C, A, target);
  
}

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> C(N);
  std::vector<int> A(N);
  for(int i=0;i<N;++i) {
    scanf("%d", &C[i]);
  }
  for(int i=0;i<N;++i) {
    scanf("%d", &A[i]);
  }
  const int sol = SolveSlow(C, A);
  printf("%d\n", sol);
  return 0;
}

