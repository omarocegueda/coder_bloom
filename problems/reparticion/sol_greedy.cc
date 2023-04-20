#include <string.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


int SolveGreedy(const int N, const std::vector<int>& A, const std::vector<int>& B) {
  int sol = -1;
  {
    std::vector<int> idx(N);
    for(int i=0;i<N;++i) {
      idx[i] = i;
    }
    std::sort(idx.begin(), idx.end(), [&](const int& left, const int& right){ return A[left] < A[right];});
    int sum = 0;
    for(int i=0;i<N;++i) {
      if(i*2<N) {
        sum += A[idx[i]];
      } else {
        sum += B[idx[i]];
      }
    }
    sol = sum;
  }
  {
    std::vector<int> idx(N);
    for(int i=0;i<N;++i) {
      idx[i] = i;
    }
    std::sort(idx.begin(), idx.end(), [&](const int& left, const int& right){ return B[left] < B[right];});
    int sum = 0;
    for(int i=0;i<N;++i) {
      if(i*2<N) {
        sum += B[idx[i]];
      } else {
        sum += A[idx[i]];
      }
    }
    sol = std::min(sol, sum);
  }
  return sol;
}


int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(2*N);
  std::vector<int> B(2*N);
  for(int i=0;i<2*N;++i) {
    std::cin >> A[i] >> B[i];
  }  
  std::cout << SolveGreedy(2*N, A, B) << std::endl;
  return 0;
}


